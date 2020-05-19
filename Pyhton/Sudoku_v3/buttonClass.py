import pygame

class Button:
    def __init__(self, x, y, width, height, text = None, colour = (75, 75, 75), highlightedColour=(190, 190, 190), function = None, params = None):
        self.image = pygame.Surface((width, height))
        self.pos = (x, y)
        self.rect = self.image.get_rect()
        self.rect.topleft = self.pos
        self.text = text
        self.colour = colour
        self.highlightedColour = highlightedColour
        self.highligthed = False
        self.function = function
        self.params = params

    def update(self, mouse):
        if self.rect.collidepoint(mouse):
            self.highligthed = True
        else:
            self.highligthed = False

    def draw(self, window):
        self.image.fill(self.highlightedColour if self.highligthed else self.colour)
        window.blit(self.image, self.pos)


