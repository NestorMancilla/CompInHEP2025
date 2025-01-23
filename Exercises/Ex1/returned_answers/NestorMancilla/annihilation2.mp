% annihilation2.mp -- do not edit, generated automatically by feynman.tex
input feynmp
require_RCS_revision "1.30";
beginchar(1, 100*1.0pt#, 100*1.0pt#, 0);
"feynmf: 1";
LaTeX_unitlength:=1.0pt;
subgraph (0, 0, w, h);
vinit;
pickup pencircle scaled thin;
vleft (__e1, __e2);
vright (__p1, __p2);
vconnect ("fermion", __e1, __v1, __e2);
vconnect ("gluon,label=$Z^0$", __v1, __v2);
vconnect ("fermion", __p1, __v2, __p2);
vlabel ("$e^-$", __e1);
vlabel ("$e^+$", __e2);
vlabel ("$\mu ^+$", __p1);
vlabel ("$\mu ^-$", __p2);
vfreeze;
vdraw;
endsubgraph;
endchar;
% the end.
end.
endinput;
