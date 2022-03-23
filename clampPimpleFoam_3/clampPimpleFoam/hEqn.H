{
    Red = mag(U) * Deq / turbulence->nu();
    hsf = por * Kf / Deq * (2 + pow(Red, 0.5) * pow(Pr, 0.3333));
}
