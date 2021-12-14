# Guidelines

This file presents some guidelines regarding directory structure, API, file and function naming conventions, and other considerations. Feel free to comment, edit, or propose improvements to this file or its contents.

## Directory structure

At the root level of the library, there are five main directories. These are discussed next.

### `src/ `
Contains the Jasmin source code. The internal structure is the following: `src/operation/primitive/architecture/implementation`. The following itemize describes each hierarchical level:
 
 * `operation` : a cryptographic operation, for instance `crypto_stream`, `crypto_hash`, or `crypto_kem`. [SUPERCOP](https://bench.cr.yp.to/supercop.html)/[libsodium](https://github.com/jedisct1/libsodium/tree/master/src/libsodium) can be used as reference for the list of supported cryptographic operations.
 
 * `primitive` : represents a cryptographic primitive that implements a given `operation`, for instance, `chacha20` or  `shake128` are primitives of `crypto_stream` and `crypto_hash`, respectively. 
 
 * `architecture` : currently, the Jasmin compiler can only produce code for `AMD64`. Future releases of the compiler will support, for instance, `RISC-V` and `ARM64`.

 * `implementation` : there could be many implementations for the same `primitive` under each CPU architecture. Typically, each implementation provides different trade-offs: it can be optimized for space or speed; it can take advantage of architecture-dependent extensions, for instance, use some specific CPU instructions or instructions sets such as `AVX2`. In the context of `AMD64`, common names are `ref`, `avx`, and `avx2`. These names are not mandatory, but the implementation name should provide a hint regarding the implementation type. An additional `README.md` file can be placed in the implementation folder to present/discuss any relevant detail about it.

#### `common/` directories under `src/`

Write me.

### `proof/`

Write me.

### `test/`

Write me.

### `bench/`

Write me.

### `doc/`

Write me.

## API

Write me.

## Naming Conventions

This section details naming conventions for:
* Directories 
* File names and extensions
* Function names
* Global parameters and constants names

As a general observation, *under_score* case should be used instead of *CamelCase*.

### Directory names

It is strongly recommended to avoid hyphens (`-`) in any path and use underscores (`_`) instead. Since Jasmin function names cannot contain hyphens, and also that some namespacing conventions (or automatic mechanism to implement namespacing) will be required soon, the usage of hyphens should be avoided to eliminate a possible source of conflicts.

Regarding `RISC-V`: given that `AMD64` code will be under a directory named `amd64`, `risc_v` (or `RISC_V`; or `riscv`) can be used. *TODO*: propose a final name for `RISC-V`.

### File names and File Extensions

#### Source Code

There are two main file extensions for Jasmin source code:
* `.jinc` : for any file that contains Jasmin code that do not contain any `export` functions definitions. `.jinc` files can `require` other `.jinc` files.
* `.jazz` : for files that only contain `export`ed functions. For instance `crypto_kem/kyber/kyber768/amd64/ref` should define a `kem.jazz` file that exports the functions expected by the operation. The same for `crypto_stream/chacha20/amd64/ref`, which defines a file `stream.jazz`. These `*.jazz` files should define exported functions with namespacing in mind, for instance, `export fn crypto_stream_chacha20_amd64_ref`.

#### Proofs

Write me.

* `*_spec.ec` : EasyCrypt specification of a given primitive.
* `*_src_*.ec` : Extracted EasyCrypt code from a given implementation. 


### Function names

Currently, there are three types of functions in Jasmin: `inline`; `local`; and `export`. The proposed guideline for this is to use:
1. `__` (2 underscores) prefix for any function that is inlined;
2. `_` (1 underscore) prefix for any function that is `local` (note: a `local` function does not require a `local` keyword to be declared);
3. no underscores for `export` functions.

The advantages in following this guideline:

*TODO*: present a scenario where this is advantageous. 

### Global params and variables

Any global parameter or global variable name should be written in `ALL_CAPS`. 


## General considerations

* The usage of preprocessors such as `gpp` or `gcc -E` should be avoided whenever possible. If it is impossible to avoid preprocessors for some particular reason, this should be justified (for instance, in a README.md file under the implementation's directory), and an issue should be opened on the [Jasmin GitHub repository](https://github.com/jasmin-lang/jasmin) to initiate a discussion on how to fix the problem.





