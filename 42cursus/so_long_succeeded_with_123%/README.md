*This project has been created as part of the 42 curriculum by jshim.*

# so_long

## Description

A small 2D top-down game built in C using MiniLibX. The player navigates a tile-based map, collects all items (`C`), and reaches the exit (`E`). The game tracks and displays the move count both in the shell and on-screen. Bonus features include enemy patrols that end the game on contact and animated enemy sprites.

---

## Instructions

**Dependencies:** MiniLibX (Linux), libft, ft_printf — all compiled automatically via their own Makefiles.

```bash
# build
make          # mandatory build
make bonus    # bonus build (enemies + animation)

# Run
./so_long maps/map.ber
```

**Controls:** `W` `A` `S` `D` to move · `ESC` to quit · window close button also exits cleanly.

**Map format:** `.ber` text file using `1` (wall), `0` (empty), `P` (player start), `C` (collectible), `E` (exit), `M` (enemy, bonus).

---

## Key Technical Notes

### MiniLibX (MLX)

MiniLibX is a minimal X11-based graphics library developed at 42. The core workflow is:

1. `mlx_init()` — create a display connection
2. `mlx_new_window()` — open a window (sized to `map_w * tile_size` × `map_h * tile_size`)
3. `mlx_xpm_file_to_image()` — load XPM sprites into memory
4. `mlx_put_image_to_window()` — blit a sprite at a given pixel coordinate
5. `mlx_key_hook()` / `mlx_hook()` — register keyboard and window-close callbacks
6. `mlx_loop_hook()` — register a per-frame update function (used for animation)
7. `mlx_loop()` — hand control to the event loop (blocking)

Each tile is rendered by first drawing the background (`empty.xpm`) and then overlaying the tile's sprite if it exists. This avoids transparent-pixel artifacts from previous frames. The move counter is drawn with `mlx_string_put()` directly onto the window each render.

### Map Validation Algorithm

Validation runs in three sequential passes:

**Pass 1 — Shape & walls** (`check_rectangle_and_walls`): every row must have the same length as the first row, and every border cell must be `1`.

**Pass 2 — Element counts** (`count_elements` / `validate_components`): exactly one `P`, exactly one `E`, at least one `C`. Any unrecognized character is also rejected here.

**Pass 3 — Reachability** (`validate_path`): a deep-copy of the map is flood-filled (DFS) starting from `P`. The fill marks reachable cells as `V`.

#### DFS / Flood Fill

`flood_fill` is a recursive DFS that expands in four directions, stopping at walls (`1`) and **exits** (`E`). After the fill, every `C` cell must be marked `V` (reachable), and every `E` cell must be *adjacent* to a `V` cell (`is_beside_v`).

#### Why `C` and `E` are treated differently

The flood fill deliberately does **not** enter `E` tiles. This reflects the game rule that the exit only opens after all collectibles are gathered — but for pathfinding purposes what actually matters is:

- A `C` must be *directly visitable*, so it must become `V` during the fill.
- An `E` must be *reachable from an adjacent tile*, not entered itself. Entering `E` during the flood fill would allow the fill to "pass through" the exit and potentially count paths that go around uncollected items.

Keeping `E` as a boundary ensures the check is: *can the player stand next to the exit?* — which is the correct reachability condition.

---

## Resources

### MiniLibX
- [MiniLibX Linux documentation (harm-smits)](https://harm-smits.github.io/42docs/libs/minilibx)
- [MiniLibX Linux source on GitHub](https://github.com/42Paris/minilibx-linux)
- [XPM format overview — Wikipedia](https://en.wikipedia.org/wiki/X_PixMap)

### Algorithms
- [Flood fill — Wikipedia](https://en.wikipedia.org/wiki/Flood_fill)
- [DFS explanation — cp-algorithms](https://cp-algorithms.com/graph/depth-first-search.html)

### 42 Project References
- [so_long project page — 42 intra](https://projects.intra.42.fr/projects/so_long)

### AI Usage
Claude (Anthropic) was used to assist with: drafting and structuring this README; reviewing the flood-fill logic for edge cases; and explaining MiniLibX event loop behavior. All code was written, understood, and verified by the author.