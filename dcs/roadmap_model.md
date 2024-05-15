---
title: markmap
markmap:
#   color:
#     - '#f9dc3e' # yellow
  colorFreezeLevel: 3 # Colored
#   color: '#2980b9'
  maxWidth: 300 # largura do map
  embedAssets: true # embed images
  initialExpandLevel: -1 # -1: all collapsed
---

## heading 1

- item 1 <!-- markmap: foldAll -->
  - item 1.1
    - item 1.1.1
  - item 1.2
    - item 1.2.1
- item 2

## heading 2 <!-- markmap: fold -->

- item 3
  - item 3.1
- item 4
  - item 4.1

## Links

- [Website](https://markmap.js.org/) <!-- markmap: foldAll -->
  - [GitHub]
- [GitHub](https://github.com/gera2ld/markmap)

## Related Projects

- [coc-markmap](https://github.com/gera2ld/coc-markmap) for Neovim
- [markmap-vscode](https://marketplace.visualstudio.com/items?itemName=gera2ld.markmap-vscode) for VSCode
- [eaf-markmap](https://github.com/emacs-eaf/eaf-markmap) for Emacs

## Features

Note that if blocks and lists appear at the same level, the lists will be ignored.

### Lists

- **strong** ~~del~~ *italic* ==highlight==
- `inline code`
- [x] checkbox
- Katex: $x = {-b \pm \sqrt{b^2-4ac} \over 2a}$ <!-- markmap: fold -->
  - [More Katex Examples](#?d=gist:af76a4c245b302206b16aec503dbe07b:katex.md)
- Now we can wrap very very very very long text based on `maxWidth` option

### Blocks

```js
console.log('hello, JavaScript')
```

| Products | Price |
|-|-|
| Apple | 4 |
| Banana | 2 |

![](/favicon.png)