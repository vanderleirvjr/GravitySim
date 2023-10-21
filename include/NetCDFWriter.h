// NetCDFWriter.h
#pragma once

#include "ObjectManager.h"
#include <netcdf>


class NetCDFWriter {
public:
    NetCDFWriter(const std::string& filename);
    ~NetCDFWriter();

    void writeParticles(ObjectManager& manager, int time_step);
private:
    netCDF::NcFile ncfile;
    netCDF::NcDim timeDim;
};
