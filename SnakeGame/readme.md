# Snake Game — Documentation

## Overview

A lightweight, single‑file Snake game implemented in vanilla HTML/CSS/JS. Drop the file on any modern browser and play—no build tools, no dependencies.

* **File:** `snake.html` (the one in your canvas)
* **Storage:** Best score persisted in `localStorage`

## Features

* Pause/Resume, Restart
* Wrap‑walls toggle (On/Off)
* Three speed presets (Slow/Normal/Fast) with gentle auto‑ramp on every 5 foods
* Keyboard (Arrows/WASD) + touch D‑pad + swipe
* Responsive, crisp rendering on HiDPI displays
* Accessible labels and clear UI

## Quick Start

1. Save the code as `snake.html`.
2. Open it in a modern browser (Chrome, Edge, Firefox, Safari).
3. Click **▶️ Play** or press any movement key to start.

## Controls

* **Movement:** Arrow Keys or WASD
* **Pause/Resume:** `P` or the Pause/Resume button
* **Restart:** `R` or the Restart button
* **Speed:** Keys `1` (Slow), `2` (Normal), `3` (Fast) or the Speed button
* **Wrap Toggle:** `W` (capital W) or the Wrap button
* **Touch:** D‑pad buttons or swipe on the canvas

## Game Options (UI)

* **Wrap:** Teleport through walls when on; die on wall impact when off.
* **Speed:** Slow / Normal / Fast (also auto increases slightly every 5 foods eaten).

## Code Structure

The script is self‑contained inside an IIFE.

### Constants

* `GRID = 24` — number of cells both horizontally and vertically
* `CELL = 24` — base cell pixel size (rendering scales to device pixel ratio)
* `START_LEN = 4` — initial snake length
* `SPEEDS = { slow: 7, normal: 11, fast: 15 }` — cells per second

### DOM & Canvas Setup

* HiDPI‑aware sizing via `ResizeObserver`, scaling by `devicePixelRatio`.
* Elements: score, best, overlay (play/pause/game‑over card), controls, touch D‑pad.

### Core State

* `snake` (Array<{x,y}>) — head at index 0
* `dir` / `nextDir` — current & queued direction
* `food` — single food cell `{x,y}`
* `score` — current score
* `tickRate` — updates per second (cells/s)
* `running`, `dead`, `wrapWalls`
* `timeAcc`, `lastTs` — fixed‑step accumulator

### Main Functions

* `reset()` — initialize state, place snake/food, show overlay
* `start() / pause()` — run/pause the game
* `placeFood()` — pick a random empty cell
* `step()` — fixed‑timestep logic: move head, check wrap/bounds, self‑collision, eat food, grow, update score/best
* `gameOver()` — stop, persist best, show overlay
* `render(ts)` — draw background, grid, food glow, snake body with gradient, head eye
* `frame(ts)` — RAF loop, fixed‑step accumulator (`timeAcc` vs `1/tickRate`)

### Input Handling

* Keyboard map for arrows/WASD, `P`, `R`, `1/2/3`, `W`
* Click handlers for Pause/Resume, Restart, Play, Wrap, Speed
* Touch D‑pad and swipe detection (thresholded)

## Game Loop & Timing

* Uses `requestAnimationFrame(frame)` for smooth rendering.
* **Fixed‑step simulation**: physics advances in equal time quanta (`1 / tickRate`), even if rendering is variable. Accumulator pattern ensures consistent speed regardless of frame rate.

## Rendering Details

* Subtle gradient board, grid lines, rounded cells.
* Snake color varies along its body (teal → green) for depth cues.
* Food has a soft glow (shadow blur).
* Canvas is square and scales responsively; aspect ratio maintained via CSS.

## Persistence

* Best score is saved under key `snake.best.v1` in `localStorage`.

## Accessibility

* Canvas has `role="img"` and an `aria-label`.
* Buttons include clear labels and focusable targets; overlay text explains controls.

## Customization Guide

### Change Grid Size

```js
const GRID = 24; // try 20 (easier) or 30 (harder)
```

* The logic and rendering derive from `GRID`, so everything resizes correctly.

### Change Speeds

```js
const SPEEDS = { slow: 7, normal: 11, fast: 15 };
```

* Increase values for a snappier game. The auto‑ramp adds +1 every 5 foods.

### Disable Auto‑Ramp

Remove this line in `step()`:

```js
if (score % 5 === 0 && tickRate < SPEEDS.fast) tickRate += 1;
```

### Walls Always Solid (no wrap)

Set default in `reset()`:

```js
wrapWalls = false; // default off
```

### Colors & Theme

* Adjust CSS variables in `:root` for quick palette swaps, e.g. `--accent`, `--panel`, `--bg`.

### Add Obstacles (starter idea)

1. Add `const obstacles = []` and populate with `{x,y}` cells not overlapping snake/food.
2. In `render()`, draw them before the snake.
3. In `step()`, before moving tail, check if `nx,ny` matches any obstacle → `gameOver()`.

### Sound Effects (starter idea)

* Hook into events in `step()` when eating or dying; play short WebAudio/HTMLAudio clips.

## Troubleshooting

* **Game feels too fast/slow**: tune `SPEEDS` or toggle speed with `1/2/3`.
* **Blurry on HiDPI**: the canvas rescales via DPR; ensure the `<canvas>` has CSS width set (it is) and your browser zoom isn’t extreme.
* **Keys not working**: some browsers/apps intercept `Ctrl+W`. The code prevents default only for `Ctrl+W` (tab close). Use arrows instead.

## Browser Support

* Modern Chromium, Firefox, and Safari (desktop and mobile). Requires ES6 features (arrow functions, `const/let`).

## License

Do anything you want with it. No warranty.

## Changelog

* v1.0 (2025‑10‑02): Initial public single‑file release with wrap walls, speed presets, touch controls, and local best.
