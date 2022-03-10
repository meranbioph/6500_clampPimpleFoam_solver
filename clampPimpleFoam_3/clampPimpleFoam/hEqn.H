{
    Red = mag(U) * Deq / turbulence->nu();
    hsf = Kf / Deq * (2 + pow(Red, (1/2)) * pow(Pr, (1/3)));
}
