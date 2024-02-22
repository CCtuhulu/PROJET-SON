import("stdfaust.lib");

transpose(w, x, s, sig) = de.fdelay(maxDelay,d,sig)*ma.fmin(d/x,1) +
    de.fdelay(maxDelay,d+w,sig)*(1-ma.fmin(d/x,1))
with {
    maxDelay = 1000;
    i = 1 - pow(2, s/12);
    d = i : (+ : +(w) : fmod(_,w)) ~ _;
};

gainChanger	= hslider("Volume", 0, -70, +20, 0.1) : ba.db2linear : si.smoo;
frequenceChanger = transpose(1000,10,hslider("Frequence", 0, -20, +20, 0.1));
echoChanger = ef.echo(0.25,0.25,hslider("Echo", 0, 0, 0.25, 0.05));

process	= echoChanger:frequenceChanger:*(gainChanger);
