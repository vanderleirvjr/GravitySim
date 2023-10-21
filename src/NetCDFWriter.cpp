#include "NetCDFWriter.h"
#include <iostream>

NetCDFWriter::NetCDFWriter(const std::string& filename)
    : ncfile(filename, netCDF::NcFile::replace)
{
    timeDim = ncfile.addDim("time");
    ncfile.addDim("particle");

    std::vector<netCDF::NcDim> dims;
    dims.push_back(ncfile.getDim("time"));
    dims.push_back(ncfile.getDim("particle"));

    std::vector<netCDF::NcDim> idims;
    idims.push_back(ncfile.getDim("particle"));


    ncfile.addVar("name", netCDF::NcType::nc_STRING, idims);
    ncfile.addVar("xo", netCDF::NcType::nc_DOUBLE , dims);
    ncfile.addVar("yo", netCDF::NcType::nc_DOUBLE, dims);
    ncfile.addVar("zo", netCDF::NcType::nc_DOUBLE, dims);
    ncfile.addVar("vx", netCDF::NcType::nc_DOUBLE, dims);
    ncfile.addVar("vy", netCDF::NcType::nc_DOUBLE, dims);
    ncfile.addVar("vz", netCDF::NcType::nc_DOUBLE, dims);
    ncfile.addVar("radius", netCDF::NcType::nc_DOUBLE, dims);
}

NetCDFWriter::~NetCDFWriter()
{
    // Destructor: NetCDF file is closed automatically
}

void NetCDFWriter::writeParticles(ObjectManager& manager, int time_step)
{
    size_t num_particles = manager.getObjectCount();
    std::vector<double> xo(num_particles), yo(num_particles), zo(num_particles),
                         vx(num_particles), vy(num_particles), vz(num_particles),
                         radius(num_particles);
    std::vector<std::string> names(num_particles);  

    for (size_t i = 0; i < num_particles; ++i) {
        Object obj = manager.getObjectAt(i);
        Particle particle = obj.getParticle();
        names[i] = particle.name; 
        xo[i] = particle.position.x;
        yo[i] = particle.position.y;
        zo[i] = particle.position.z;
        vx[i] = particle.velocity.x;
        vy[i] = particle.velocity.y;
        vz[i] = particle.velocity.z;
        radius[i] = particle.radius;
    }

    // Write to NetCDF variables
    std::vector<size_t> startp = {static_cast<size_t>(time_step), 0};
    std::vector<size_t> countp = {1, num_particles};


    if (time_step == 0) {
        ncfile.getVar("name").putVar(startp, countp, names.data());
    }


    ncfile.getVar("xo").putVar(startp, countp, xo.data());
    ncfile.getVar("yo").putVar(startp, countp, yo.data());
    ncfile.getVar("zo").putVar(startp, countp, zo.data());
    ncfile.getVar("vx").putVar(startp, countp, vx.data());
    ncfile.getVar("vy").putVar(startp, countp, vy.data());
    ncfile.getVar("vz").putVar(startp, countp, vz.data());
    ncfile.getVar("radius").putVar(startp, countp, radius.data());
}
