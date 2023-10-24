import bpy
import netCDF4
import numpy as np

# Function to convert normalized energy to RGB color
def energy_to_color(energy):
    if energy < 0.5:
        return (0, energy * 2, 1 - energy * 2)
    else:
        return (energy * 2 - 1, 2 - energy * 2, 0)
    
# Clear mesh objects in the scene
bpy.ops.object.select_all(action='DESELECT')
bpy.ops.object.select_by_type(type='MESH')
bpy.ops.object.delete()

# Open the NetCDF file
ncfile = "/Users/vanderlei.vargas/Priority/Personal/C++/workspace/GravitySim/bin/particles.nc"
nc = netCDF4.Dataset(ncfile, 'r')

# Get the time steps and number of particles
time_steps = len(nc.dimensions['time'])
num_particles = len(nc.dimensions['particle'])

# Get the particle positions, radii, and energy
x = nc.variables['xo'][:]
y = nc.variables['yo'][:]
z = nc.variables['zo'][:]
radius = nc.variables['radius'][:]
energy = nc.variables['energy'][:]

# Normalize energy
energy_min = np.min(energy)
energy_max = np.max(energy)
energy_normalized = (energy - energy_min) / (energy_max - energy_min)

# Scale factor for visualization
scale_factor = 1e3  # Adjust this as needed

# Create Blender objects at initial positions
created_objects = []
initial_time_step = 0
for i in range(num_particles):
    bpy.ops.mesh.primitive_uv_sphere_add(
        radius=radius[initial_time_step][i] / 2e3,
        location=(
            x[initial_time_step][i] / scale_factor,
            y[initial_time_step][i] / scale_factor,
            z[initial_time_step][i] / scale_factor
        )
    )

    # Get the created object
    obj = bpy.context.object

    # Create a material and assign a color based on energy
    mat = bpy.data.materials.new(name=f"EnergyMaterial_{i}")
    mat.use_nodes = True
    mat.node_tree.nodes["Principled BSDF"].inputs[0].default_value = (*energy_to_color(energy_normalized[initial_time_step][i]), 1)
    
    obj.data.materials.append(mat)
    
    # Add to our list
    created_objects.append((obj, mat))
    
    # Manually set this object to be selected
    obj.select_set(True)

# Loop through each time step to insert keyframes for each object
for time_step in range(1, time_steps):
    for i, (obj, mat) in enumerate(created_objects):
        obj.location.x = x[time_step][i] / scale_factor
        obj.location.y = y[time_step][i] / scale_factor
        obj.location.z = z[time_step][i] / scale_factor
        obj.keyframe_insert(data_path="location", frame=time_step * 1)  # Insert keyframe for position

        # Update material color based on energy at current time_step
        mat.node_tree.nodes["Principled BSDF"].inputs[0].default_value = (*energy_to_color(energy_normalized[time_step][i]), 1)
        mat.node_tree.nodes["Principled BSDF"].inputs[0].keyframe_insert(data_path="default_value", frame=time_step * 1)  # Insert keyframe for color

nc.close()
