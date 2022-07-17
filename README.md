# LTS 

Provides a simple templated implementation of Labelled Transition System, with the three following template parameters:
- StateT: the type of the state (defaults to `std::string`)
- TransitionT: the type of transitions (defaults to `std::string`)
- HashF: the hash function that is used when storing the state type in the underlying unordered_map container. Defaults to `std::hash<StateT>`.

# Acknowledgements

This work was supported by the SURE projects fund of the University of Bradford.