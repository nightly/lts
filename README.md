# LTS 

![standard](https://img.shields.io/badge/c%2B%2B-20-blue.svg)
![ci.yml](https://github.com/nightly/lts/actions/workflows/ci.yml/badge.svg)

Templated implementation of a Labelled Transition System class, with the three following template parameters:
- StateT: the type of the state (defaults to `std::string`)
- TransitionT: the type of transitions (defaults to `std::string`)
- HashF: the hash function that is used when storing the state type in the underlying unordered_map container. Defaults to `std::hash<StateT>`.

## Build instructions
### Requirements
- [CMake](https://cmake.org/) (>=3.22)
- [Git](https://git-scm.com/) (for submodule cloning)
- C++20 compiler

### Cloning & updating
Clone the repository alongside its submodules (shallow submodule cloning is optional).
```
git clone --recurse-submodules --shallow-submodules https://github.com/nightly/lts
```

In case submodules have not been cloned, the following command can be run:
```
git submodule update --init --recursive
```

## Acknowledgements

This work was supported by the SURE projects fund of the University of Bradford.