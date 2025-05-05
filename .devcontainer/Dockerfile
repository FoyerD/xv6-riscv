# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.234.0/containers/debian/.devcontainer/base.Dockerfile

# [Choice] Debian version (use bullseye on local arm64/Apple Silicon): bullseye, buster
ARG VARIANT="buster"
FROM mcr.microsoft.com/vscode/devcontainers/base:0-${VARIANT}
USER root

# ** [Optional] Uncomment this section to install additional packages. **
 RUN apt-get update && \
     apt-get install -y --no-install-recommends gdb-multiarch qemu-system-misc gcc-riscv64-linux-gnu binutils-riscv64-linux-gnu && \
     rm -rf /var/lib/apt/lists/*
RUN apt-get update
RUN apt-get upgrade -y
RUN echo "deb http://deb.debian.org/debian bullseye main contrib non-free" > /etc/apt/sources.list
RUN apt-get update
RUN apt-get install -y git build-essential gdb-multiarch qemu-system-misc gcc-riscv64-linux-gnu binutils-riscv64-linux-gnu 
# enable loading custom .gdbinit per folder.
# RUN echo set auto-load safe-path / > /root/.gdbinit
RUN echo set architecture riscv:rv64 > /root/.gdbinit