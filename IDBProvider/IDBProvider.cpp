// IDBProvider.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"



class IDBProvider {
public:
    virtual char* GetName() = 0;

    virtual char* GetSurname() = 0;

};