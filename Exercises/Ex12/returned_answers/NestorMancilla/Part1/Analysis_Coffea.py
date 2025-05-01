#!/usr/bin/env python

import sys
import os
import datetime
import matplotlib.pyplot as plt
import awkward as ak
import dask
import dask_awkward as dak
import hist
import hist.dask as hda

import uproot

from coffea import nanoevents
from coffea.nanoevents import NanoEventsFactory, NanoAODSchema
from coffea import processor
from coffea.nanoevents.methods import candidate, vector

class Analysis(processor.ProcessorABC):
    def __init__(self):
        self.histograms = {}
        self.histograms["h_pileup"] = (
            hda.Hist.new
            .Reg(100, 0, 100, name="pileup", label="Number of primary vertices")
            .Double()
        )

    def process(self, events):
        trigger_mask = events.HLT.IsoMu24
        pileup = events.PV.npvs
        self.histograms["h_pileup"].fill(pileup=pileup[trigger_mask])
        
        if ak.sum(trigger_mask) > 0:
            muons = events.Muon[trigger_mask]

        return self.histograms

    def postprocess(self, accumulator):
        pass

def main():
    filename = "file://DYJetsToLL.root"
    events = NanoEventsFactory.from_root(
        {filename: "Events"},
        metadata={"dataset": "DYJetsToLL"},
        schemaclass=NanoAODSchema,
    ).events()
    
    p = Analysis()
    out = p.process(events)
    result = dask.compute(out)[0]

    with uproot.recreate("output.root") as fOUT:
        days = ["Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"]
        now = datetime.datetime.now()
        m = "produced: %s %s"%(days[now.weekday()],now)
        fOUT[f"{m}"] = ""

        for key in result.keys():
            fOUT[f"{key}"] = result[key]

    fig, ax = plt.subplots(figsize=(10, 6))
    result["h_pileup"].plot(ax=ax)
    ax.set_xlabel("Number of primary vertices")
    ax.set_ylabel("Events")
    ax.set_title("Pileup distribution")
    plt.savefig("pileup_distribution.png")
    plt.close()

if __name__ == "__main__":
    main()

