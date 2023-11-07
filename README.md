# Neutrino DIS Generator
This repository is used to simulate the deep inelastic scattering (DIS) between
neutrino and proton.

## Requirements
This repository relies on `cmake3, c++17` and `Pythia8.310`.

If you are working on `bl-0`, you can execute one of the following
commands to meet the requirements.
```bash
source ~mocen/hailing.env
# OR
source ~mocen/cvmfs.env && source /lustre/collider/mocen/project/hailing/pythia8/setup.sh
```

### To build your own pythia8
```bash
wget https://pythia.org/download/pythia83/pythia8310.tgz
tar -xvf pythia8310.tgz
cd pythia8307
./configure
make -j9
```
To use your own pythia8 in this project, you should set the environment variables:
```bash
export PYTHIA8=${YOUR_PYTHIA8_PATH}/ # e.g. export PYTHIA8=~/pythia8310/
export PATH=${PYTHIA8}/bin:$PATH
export PYTHIA8DATA=${PYTHIA8}/share/Pythia8/xmldoc/
```

## Usage
To build the program:
```bash
mkdir build install
cd build
cmake ../
make install -j8
```

To run the DIS simulation:
```bash
cd ../install/
./neutrino
```
and then you can check the secondary particles from the printed information.

If you want to change the settings of DIS interaction, you can edit
the contents of `config/neutrino.cmnd`. 