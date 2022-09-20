#pragma once

struct RightParallelepiped;

typedef struct RightParallelepiped RightParallelepiped;

struct RightParallelepiped* Constructor();

RightParallelepiped* FileConstructor(FILE* f);

void MemDestructor(RightParallelepiped* Object);

void ParallelepipedPrint(RightParallelepiped* Object);

void ParallelepipedPrintFile(FILE* f, RightParallelepiped* Object);

double AreaOfAllSurface(RightParallelepiped* Object);

double AreaOfSideSurface(RightParallelepiped* Object);

double VolumeOfParallelepiped(RightParallelepiped* Object);

double Diagonal(RightParallelepiped* Object);

double VolumeOfSphere(RightParallelepiped* Object);

double Height(RightParallelepiped* Object);

double FirtsRib(RightParallelepiped* Object);

double SecondRib(RightParallelepiped* Object);

double ThirdRib(RightParallelepiped* Object);

double Radius(RightParallelepiped* Object);
