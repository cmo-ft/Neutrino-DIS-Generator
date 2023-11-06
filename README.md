# Neutrino DIS Generator
This repository is used to simulate the deep inelastic scattering (DIS) between 
neutrino and proton.

## Requirements
This repository relies on `cmake3, c++17` and `Pythia8`.

If you are working on `bl-0`, you can execute one of the following 
commands to meet the requirements.
```bash
source ~mocen/hailing.env
# OR
source ~mocen/cvmfs.env
```

## Usage
To build the program:
```shell
mkdir build install
cd build
cmake ../
make install -j8
```

To run the DIS simulation:
```shell
cd ../install/
./neutrino
```
and then you can check the secondary particles from the printed information.

If you want to change the settings of DIS interaction, you can edit
the contents of `config/neutrino.cmnd`. 