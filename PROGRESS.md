# The Progess

## [2025/03/09] First attempt to port to CMake

Using `cmake-converter` to generate the CMakeLists.txt

### Usage

```
cmake -S "path/to/proj" -B "path/to/proj/build" -G "Visual Studio 15 2017 Win64"

cmake --build "path/to/proj/build"
```

### TESTING
- [ ] Verify the build system works

#### Possible Problems

- In `TiberianDawn.vcxproj` and `RedAlert.vcxproj` (Both line 39)

There is a XML snippet:

```xml
<Import Project="$(VCTargetsPath)\BuildCustomizations\masm.props" />
```

I don't get the meaning of `$(VCTargetsPath)` and `masm.props`, I think they are automatically handled by Visual Studio. But behaviours in CMake are **Unknown**, currently I just set `$ENV{VCTargetsPath}` in the `CMakeLists.txt`

- In `TiberianDawn.vcxproj` (line 161 and 252)

There are two absent files: `MEMCHECK.H` and `HOLD.TXT`

I still add these files to to CMakeLists, `MEMCHECK.H` can be found under the `REDALERT` directory. If the build fails, try copy this file.
