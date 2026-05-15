# Battleship

A simple naval battle simulator made in C for a college programming challenge.

This project was created to practice navigation, nested loops and conditional structures using bidimensional arrays.

Original repository: [desafio-batalha-naval-sabrigs-3](https://github.com/Cursos-TI/desafio-batalha-naval-sabrigs-3)

## Features

- 10x10 battlefield
- Horizontal, vertical and diagonal ships
- Position validation
- Collision detection
- Special attack areas
    - Cone
    - Dagger
    - Diamond

## Code structure

```mermaid
flowchart TD

    A[main] --> B[title]
    A --> C[print_battlefield]

    A --> D[Choose ship position]

    D --> E[print_ship_horizontal]
    D --> F[print_ship_vertical]
    D --> G[print_ship_diagonal1]
    D --> H[print_ship_diagonal2]

    A --> I[Special Powers]

    I --> J[print_cone]
    I --> K[print_dagger]
    I --> L[print_diamond]

    E --> M[Battlefield Array]
    F --> M
    G --> M
    H --> M
    J --> M
    K --> M
    L --> M
```