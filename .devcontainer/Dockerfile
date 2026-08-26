FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    clang \
    valgrind \
    gdb \
    git \
    make \
    curl \
    && rm -rf /var/lib/apt/lists/*