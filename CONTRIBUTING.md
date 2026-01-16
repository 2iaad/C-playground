# Contribution Guidelines

Thanks for your interest in contributing to C-playground. Contributions are welcome across exercises and subprojects.

- Code style:
  - Follow 42 Norminette spirit, keep code clear and consistent.
  - C files compile with -Wall -Wextra -Werror (see project Makefiles).
- Workflow:
  - Fork the repo, create a branch: feature/short-name or fix/short-name.
  - Make focused commits with clear messages (e.g., feat: add ft_strspn).
  - Run make clean and ensure builds pass before opening a PR.
- Project-specific:
  - 2D/3D games: keep assets and maps separate; do not commit large binaries.
  - Libraries (LibC, MyPrintf): keep APIs stable; update headers when needed.
  - Exercises: keep solutions minimal, no extra dependencies.
- Testing:
  - Provide minimal inputs demonstrating behavior (e.g., sample maps: [2D-game/map.ber](2D-game/map.ber), [3D-game/map.cub](3D-game/map.cub)).
- PRs:
  - Describe changes, affected subfolders, and build/run notes.
  - Small, reviewable diffs are preferred.

By contributing, you agree your code is MIT-licensed (see [LICENSE](LICENSE)).