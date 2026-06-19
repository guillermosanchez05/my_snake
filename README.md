# Snake (C++ / ncurses)

A simple terminal-based Snake game written in C++. This project was built as an exercise to **learn the basics of C++**.

## Requirements

- A C++ compiler (`g++`)
- `make`
- The `ncurses` development library

## Compiling

From the project root, simply run:

```bash
make
```

This compiles each source file into an object file inside `build/` and links them into an executable at `bin/my_snake`.

## Running

You can run the game with:

```bash
make run
```

or directly:

```bash
./bin/my_snake
```

## Controls

- **Arrow keys** — change the snake's direction
- **q** — quit the game

## Cleaning Build Artifacts

To remove the `build/` and `bin/` directories:

```bash
make clean
```

## About This Project

This was created purely for learning purposes, i.e. practice fundamental C++ concepts such as object-oriented design, working with the standard library, and using `make` to build a multi-file project. It is not intended to be a polished or production-ready game.

---
---

# Snake (C++ / ncurses) — Versión en Español

Un Snake sencillo hecho en la terminal y escrito en C++. Es un proyecto construido principalmente para aprender los **conceptos básicos de C++**.

## Requisitos

- Un compilador de C++ (`g++`)
- `make`
- La biblioteca de desarrollo `ncurses`

## Compilación

Desde la raíz del proyecto, simplemente ejecuta:

```bash
make
```

Esto compila cada archivo fuente en un archivo objeto dentro de `build/` y los enlaza en un ejecutable ubicado en `bin/my_snake`.

## Ejecución

Puedes ejecutar el juego con:

```bash
make run
```

o directamente:

```bash
./bin/my_snake
```

## Controles

- **Flechas del teclado** — cambian la dirección de la serpiente
- **q** — salir del juego

## Limpiar Archivos de Compilación

Para eliminar los directorios `build/` y `bin/`:

```bash
make clean
```

## Sobre Este Proyecto

Este proyecto fue creado únicamente con la finalidad de aprender, en este caso practicar conceptos fundamentales de C++ como la POO, el uso de la librería estándar y el uso de `make` para construir un proyecto con múltiples archivos. No pretende ser un juego pulido ni listo para producción.
