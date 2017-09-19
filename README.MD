# Chessman

[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/C%2B%2B-11-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE.MD)
[![Tests](https://img.shields.io/badge/passing%20tests-196-green.svg)](./game/tests)

Yet another simple chess game with not so smart AI.

## Requirements

- C++11 compilator
- CMake >= 3.5.1

Additional requirements (not needed for CLI):

- Boost >= 1.55 (for test cases)
- Qt 5.9 (for desktop GUI and Android)

## Compilation

```
mkdir build

cd build

cmake "Unix Makefiles" -DCMAKE_BUILD_TYPE=[Release|Debug] ..

cmake --build . --target [chessman-cli|tests]
```

## License

[MIT](LICENSE.MD)

