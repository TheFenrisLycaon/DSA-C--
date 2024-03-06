def cakes(recipe, available):
    if (all(x in list(available.keys()) for x in list(recipe.keys()))):
        return min([available[i] // recipe[i] for i in recipe])
    else:
        return 0