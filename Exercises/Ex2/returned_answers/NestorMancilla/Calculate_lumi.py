import re

log_file = "brilcalc.log"

pattern = r"\|\s+\d+\s+\|\s+\d+\s+\|\s+([\d\.]+)\s+\|\s+([\d\.]+)"

try:
    total_recorded_lumi_fb = 0.0  # Initialize this variable

    with open(log_file, "r") as file:
        for line in file:
            if line.startswith("#Summary:"):
                break
            
            match = re.search(pattern, line)
            if match:
                recorded_lumi_pb = float(match.group(2))
                recorded_lumi_fb = recorded_lumi_pb / 1000
                print(f"Luminosity: {recorded_lumi_fb:.1f}")
                total_recorded_lumi_fb += recorded_lumi_fb

    print(f"Total Recorded Luminosity: {total_recorded_lumi_fb:.1f} fb⁻¹")


except FileNotFoundError:
    print(f"Error: File '{log_file}' not found.")

