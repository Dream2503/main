from keyboard import send
from mss.base import MSSBase
from mss.screenshot import ScreenShot
from mss import mss
from time import sleep, perf_counter
from typing import Final

Coordinates = tuple[int, int]
RGB = tuple[int, int, int]

REFRESH_RATE: Final[float] = 1 / 165
TOGGLE_HALF_LIFE: Final[bool] = True
TOGGLE_SKILL: Final[bool] = True

LIFE_COOLDOWN_THRESHOLD: Final[float] = 0.5
MANA_COOLDOWN_THRESHOLD: Final[float] = 0.5
HALF_LIFE_COOLDOWN_THRESHOLD: Final[float] = 6
SKILL_COOLDOWN_THRESHOLDS: Final[tuple[float]] = (7.5,)

LIFE_CORDS: Final[Coordinates] = (130, 1030)
MANA_CORDS: Final[Coordinates] = (1760, 1060)
HALF_LIFE_CORDS: Final[Coordinates] = (160, 960)

LIFE_COLOUR: Final[RGB] = (79, 9, 17)
MANA_COLOUR: Final[RGB] = (24, 33, 60)
HALF_LIFE_COLOUR: Final[RGB] = (141, 19, 27)

LIFE_KEYS: Final[tuple[str, str]] = ('1', '4')
MANA_KEYS: Final[tuple[str, str]] = ('2', '5')
HALF_LIFE_KEYS: Final[tuple[str]] = ('3',)
SKILL_KEYS: Final[tuple[str]] = ("ctrl+t",)

LIFE_COUNT: Final[int] = len(LIFE_KEYS)
MANA_COUNT: Final[int] = len(MANA_KEYS)
HALF_LIFE_COUNT: Final[int] = len(HALF_LIFE_KEYS)
SKILL_COUNT: Final[int] = len(SKILL_KEYS)

POINTS: Final[dict[str, Coordinates]] = {
    "life": LIFE_CORDS,
    "mana": MANA_CORDS,
    "half-life": HALF_LIFE_CORDS,
}

MIN_X: Final[int] = min(x for x, _ in POINTS.values())
MIN_Y: Final[int] = min(y for _, y in POINTS.values())
CAPTURE_WIDTH: Final[int] = max(x for x, _ in POINTS.values()) - MIN_X + 1
CAPTURE_HEIGHT: Final[int] = max(y for _, y in POINTS.values()) - MIN_Y + 1

sct: MSSBase = mss()


def get_screenshot_pixel_colour(screen_shot: ScreenShot, coord: Coordinates, ) -> RGB:
    idx: int = ((coord[1] - MIN_Y) * screen_shot.width + (coord[0] - MIN_X)) * 4
    return screen_shot.bgra[idx + 2], screen_shot.bgra[idx + 1], screen_shot.bgra[idx]


def main() -> None:
    life_cooldown: float = 0
    mana_cooldown: float = 0
    half_life_cooldown: float = 0
    skill_cooldowns: list[float] = [0] * SKILL_COUNT
    current_life_key: int = 0
    current_mana_key: int = 0
    current_half_life_key: int = 0

    while True:
        screen_shot: ScreenShot = sct.grab({"top": MIN_Y, "left": MIN_X, "width": CAPTURE_WIDTH, "height": CAPTURE_HEIGHT})
        now: float = perf_counter()

        if LIFE_COLOUR != get_screenshot_pixel_colour(screen_shot, LIFE_CORDS):
            if not life_cooldown or now - life_cooldown >= LIFE_COOLDOWN_THRESHOLD:
                send(LIFE_KEYS[current_life_key % LIFE_COUNT])
                life_cooldown = now
                current_life_key += 1

        if MANA_COLOUR != get_screenshot_pixel_colour(screen_shot, MANA_CORDS):
            if not mana_cooldown or now - mana_cooldown >= MANA_COOLDOWN_THRESHOLD:
                send(MANA_KEYS[current_mana_key % MANA_COUNT])
                mana_cooldown = now
                current_mana_key += 1

        if TOGGLE_HALF_LIFE and HALF_LIFE_COLOUR != get_screenshot_pixel_colour(screen_shot, HALF_LIFE_CORDS):
            if not half_life_cooldown or now - half_life_cooldown >= HALF_LIFE_COOLDOWN_THRESHOLD:
                send(HALF_LIFE_KEYS[current_half_life_key % HALF_LIFE_COUNT])
                half_life_cooldown = now
                current_half_life_key += 1

        for i in range(SKILL_COUNT):
            if TOGGLE_SKILL and (not skill_cooldowns[i] or now - skill_cooldowns[i] >= SKILL_COOLDOWN_THRESHOLDS[i]):
                send(SKILL_KEYS[i])
                skill_cooldowns[i] = now

        sleep(REFRESH_RATE)


if __name__ == "__main__":
    try:
        sleep(2)
        # print(get_screenshot_pixel_colour(LIFE_CORDS))
        # print(get_screenshot_pixel_colour(MANA_CORDS))
        # print(get_screenshot_pixel_colour(HALF_LIFE_CORDS))
        main()

    except KeyboardInterrupt:
        pass

    finally:
        sct.close()
