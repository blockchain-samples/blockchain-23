# Blockchain
Test of some simple blockchain code.

### What is Blockchain
What is Blockchain in general you can find here: https://en.wikipedia.org/wiki/Blockchain.  
I find that the next article may be helpful: http://davenash.com/2017/10/build-a-blockchain-with-c/.  
As part of the code I use SHA-256 hash function from this repo: https://github.com/sam0delk1n/sha-256.

### How to build and run
Clone the repo.
```bash
git clone https://github.com/sam0delk1n/blockchain.git
```
Create `build/Debug` and `build/Release` folders in the repo root folder.
```bash
cd blockchain
mkdir build
cd build
mkdir Debug Release
```
Build Debug version. You need CMake 3.10.2 and GCC-7/g++-7.
```bash
cd Debug
cmake -DCMAKE_BUILD_TYPE=Debug ../..
make
```
Run.
```bash
./blockchain
```
Then do the same for Release.
```bash
cd ../Release
cmake -DCMAKE_BUILD_TYPE=Release ../..
make
./blockchain
```

### How to build and run with Docker
What is Docker please read here: https://docs.docker.com/.  

If you don't have required compilers or tools, you can build and run this project with Docker. Before start, please delete `build` folder if you've already create it.
```bash
cd blockchain
docker build -t blockchain .
```
Docker downloads Linux Bionic image with GCC-7/g++-7 and CMake that are already installed. Then Docker builds the project into `/home/app/build/Debug` and `home/app/build/Release` (inside the image) respectively and containerizes into the image with name `blockchain`. Now you can run the program.
```bash
docker run blockchain /home/app/build/Debug/blockchain
docker run blockchain /home/app/build/Release/blockchain
```
