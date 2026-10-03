<picture>
  <source media="(prefers-color-scheme: dark)" srcset="docs/banner-dark.svg" />
  <img src="docs/banner-light.svg" width="100%" alt="smalloc: A small malloc written from scratch on top of mmap, to learn how memory allocation really works." />
</picture>

this repo explores the inner workings of memory allocation by implementing a small version of the malloc function in C. in this project i'm aiming to get a deep understanding of how the operating system manages memory and the concepts behind dynamic memory allocation.

<picture>
  <source media="(prefers-color-scheme: dark)" srcset="docs/layout-dark.svg" />
  <img src="docs/layout-light.svg" width="100%" alt="smalloc(1000) maps one page: a 24-byte mt_data header followed by the 1000-byte payload" />
</picture>

<picture>
  <source media="(prefers-color-scheme: dark)" srcset="docs/roadmap-dark.svg" />
  <img src="docs/roadmap-light.svg" width="100%" alt="Today one mmap per call; planned: one zone with a linked free list" />
</picture>

## Run it

```bash
cc smalloc.c -o smalloc && ./smalloc   # main() fills a 1000-byte block with 'a'
```

<sub>Diagrams in <code>docs/</code> are generated SVGs, drawn to match the code in this repo.</sub>
