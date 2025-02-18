# BoyJack OS Kernel Setup and Build Guide

This guide provides instructions on how to set up, configure, and build the kernel for BoyJack OS. The kernel is the core component of the operating system and must be compiled and configured properly to support your hardware.

## Prerequisites

Before building the kernel, ensure you have the following installed:

- A Linux-based operating system (Ubuntu, Debian, etc.)
- GCC (GNU Compiler Collection)
- Make
- Git
- Required kernel dependencies (e.g., `libncurses-dev`, `bc`, `flex`, `bison`)

You can install the required dependencies on Ubuntu/Debian by running:

```bash
sudo apt update
sudo apt install gcc make git libncurses-dev bc flex bison

## Cloning the Repository
First, clone the BoyJack OS kernel repository:

```bash
git clone https://github.com/deniselksina/BoyJack-OS.git
cd BoyJack-OS

## Kernel Configuration

Navigate to the kernel directory:
```bash
cd kernel

Apply any required patches (if applicable):
```bash
patch -p1 < patches/0002-add-support-for-device.patch

Configure the kernel:

You can use the default configuration provided in the defconfig file:
```bash
cp defconfig .config

Alternatively, you can manually configure the kernel by running:
```bash
make menuconfig

This command will open a text-based menu for configuring kernel options. Select the options based on your hardware and requirements.

## Building the Kernel

Once the kernel is configured, build it by running:
```bash
make -j$(nproc)

The -j$(nproc) flag allows the build to use all available CPU cores for faster compilation.
After the build completes, the kernel image will be available as arch/arm/boot/zImage.

## Installing the Kernel

To install the compiled kernel, copy the image to the boot partition:
```bash
sudo cp arch/arm/boot/zImage /boot/

You may need to update your bootloader configuration to point to the new kernel image.

## Kernel Modules

If you're building kernel modules, use the following commands to build and install them:
```bash
make modules
sudo make modules_install

This will compile and install any modules required for your hardware.

## Rebuilding After Changes

If you make any changes to the kernel source code or configuration, you can rebuild the kernel using the following commands:
```bash
make clean
make -j$(nproc)

## Troubleshooting

If you encounter issues during compilation, ensure that all dependencies are installed correctly and that the kernel configuration is set properly.
For specific hardware support, check the relevant documentation or patches.
