# CHIP-8 Emulator

Welcome to my CHIP-8 Emulator side-project written using C++. This is meant to reinforce the learning I received from my _Computer Organization_ course. The resource that is being used is a popular resource [here](https://austinmorlan.com/posts/chip8_emulator/#what-is-an-emulator). I highly encourage following along through this guide as it will make understanding my code a lot easier. The comments given are also directly referenced to this resource as well.

# What is an Emulator?

To put it brief, an emulator is essentially just a virtual machine in where it uses an interpreter to run all of these commands that are built. The main thing that runs this however is something called a CPU. A CPU reads instructions from somewhere in memory and from that, it does whatever it was told to do. It's very fast but can be a little short-minded. 

## Components of CHIP-8

The following components were used, which were again referenced from the previous website mentioned.

- 16 8-bit Registers
- 4K Bytes of Memory
- 16-bit Index Register
- 16-bit Program Counter
- 16-level Stack
- 8-bit Stack Pointer
- _etc.. (More can be found from this website [here](https://austinmorlan.com/posts/chip8_emulator/#chip-8-description))_

# Video Demo

Once the build is fully complete, for now, this will just have to be empty. Thanks for understanding