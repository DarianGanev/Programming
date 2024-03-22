import random

class Ability:
    def __init__(self, name, damage):
        self.name = name
        self.damage = damage

class LeagueHero:
    def __init__(self, x, y, hero_type, health, damage, mana, abilities=None, current_health=100):
        self.__coords = (x, y)
        self.__hero_type = hero_type
        self.__max_health = health
        self.__current_health = health * current_health / 100
        self.__max_mana = mana
        self.__current_mana = mana
        self.__damage = damage
        self.abilities = abilities or []

    def __str__(self):
        return f"Hero {self.__hero_type} is with {self.__current_health} health currently"

    def attack(self, other):
        chance = random.randint(0, 9)
        current_damage = self.__damage
        if chance == 9:
            current_damage = current_damage * 3
        other.take_damage(current_damage)

    def use_ability(self, ability_index):
        if 0 <= ability_index < len(self.abilities):
            ability = self.abilities[ability_index]
            print(f"Hero {self.__hero_type} used {ability.name} for {ability.damage} damage!")
            self.__current_mana -= 50
            if self.__current_mana < 0:
                self.__current_mana = 0
            return ability.damage
        else:
            print("Invalid ability index")
            return 0

    def take_damage(self, damage):
        self.__current_health -= damage
        if self.__current_health <= 0:
            self.__current_health = 0
            print(f"Hero {self.__hero_type} died GG")

    def is_alive(self):
        return self.__current_health > 0

hook_ability = Ability("Hook", 150)
spin_ability = Ability("Spin Attack", 100)

tkresh = LeagueHero(0, 0, "Tkresh", 1500, 120, 600, abilities=[hook_ability])

masterYi = LeagueHero(10, 10, "Master Yi", 1800, 80, 800, abilities=[spin_ability])

print(tkresh)
print(masterYi)

while tkresh.is_alive() and masterYi.is_alive():
    tkresh.attack(masterYi)
    masterYi.attack(tkresh)

    tkresh_damage = tkresh.use_ability(0)
    masterYi_damage = masterYi.use_ability(0)
    if tkresh_damage != 0:
        print(f"\nTkresh dealt {tkresh_damage} damage.")
    if masterYi != 0:
        print(f"Master Yi dealt {masterYi_damage} damage.")
    tkresh.take_damage(masterYi_damage)
    masterYi.take_damage(tkresh_damage)

    print(tkresh)
    print(masterYi)