# 1. Header only
```bash
cd ./src/01_header_only
git clone https://github.com/nlohmann/json.git
cmake -B build
cmake --build ./build -- VERBOSE=1
./build/header_only
```

# 2. Linking
```bash
cd ../02_linking
# Собираем GTest https://github.com/google/googletest/blob/main/googletest/README.md
git clone https://github.com/google/googletest.git
cd googletest
mkdir build
cd build
cmake .. -DBUILD_GMOCK=OFF
make
# Собираем проект
cd ../..
cmake -B build
cmake --build ./build -- VERBOSE=1
./build/linking
```

# 3. Make
```bash
cd ../03_make
# Собираем openSSL https://github.com/openssl/openssl/blob/master/INSTALL.md#unix--linux--macos--nonstop
git clone https://github.com/openssl/openssl.git
cd openssl
./Configure
make -j$(nproc)
# Собираем проект
cd ..
cmake -B build
cmake --build ./build -- VERBOSE=1
./build/sha256_from_HelloWorld
```

# 4. Find package
```bash
cd ../04_find_package
git clone https://github.com/nlohmann/json.git
cd json
mkdir build; cd build; cmake ..
cd ../..
cmake -B build
cmake --build ./build -- VERBOSE=1
./build/find_package
```

# 5. FetchContent

https://json.nlohmann.me/integration/cmake/#supporting-both

```bash
cd ../05_FetchContent
cmake -B build
cmake --build ./build -- VERBOSE=1
./build/fetch_content
```

# 6. ExternalProject
```bash
cd ../06_ExternalProject
cmake -B build
cmake --build ./build -- VERBOSE=1
./build/external_project
```
