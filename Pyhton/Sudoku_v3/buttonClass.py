import pygame
from settings import *


class Button:
    def __init__(self, x, y, width, height, text=None, colour=(75, 75, 75), param=None, highlightedColour=(190, 190, 190)):
        self.width = width
        self.height = height
        self.image = pygame.Surface((width, height))
        self.pos = (x, y)
        self.rect = self.image.get_rect()
        self.rect.topleft = self.pos
        self.text = text
        self.font = pygame.font.SysFont("arial", cellSize//2)
        self.colour = colour
        self.highlightedColour = highlightedColour
        self.highligthed = False
        self.param = param

    def update(self, mouse):
        if self.rect.collidepoint(mouse):
            self.highligthed = True
        else:
            self.highligthed = False

    def draw(self, window):
        self.image.fill(self.highlightedColour if self.highligthed else self.colour)
        window.blit(self.image, self.pos)

        font = self.font.render(self.text, False, WHITE)
        pos = (self.pos[0]+(self.width//4), self.pos[1]+(self.height//8))

        window.blit(font, pos)

    def click(self, mousePos, mouseClick):
        if self.rect.collidepoint(mousePos) and mouseClick[0] == 1:
            return True
        return False




