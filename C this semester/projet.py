import trimesh
import numpy as np
import os

# Création de la boîte principale avec deux compartiments
def create_duobox_body():
    width, depth, height = 200, 150, 100
    wall_thickness = 4
    separator_thickness = 3

    # Base extérieure
    outer_box = trimesh.creation.box(extents=[width, depth, height])

    # Creux intérieur
    inner_box = trimesh.creation.box(extents=[
        width - 2 * wall_thickness,
        depth - 2 * wall_thickness,
        height - wall_thickness
    ])
    inner_box.apply_translation([0, 0, wall_thickness])
    
    # Séparateur intérieur
    separator = trimesh.creation.box(extents=[
        separator_thickness,
        depth - 2 * wall_thickness,
        height - wall_thickness
    ])
    separator.apply_translation([0, 0, wall_thickness])
    
    # Décaler la boîte intérieure pour qu'elle soit centrée
    inner_box.apply_translation([0, 0, 0])
    outer_box_boolean = outer_box.difference(inner_box, engine='scad')
    separator.apply_translation([0, 0, 0])

    # Ajouter séparateur
    outer_with_separator = outer_box_boolean.union(separator, engine='scad')
    
    return outer_with_separator

# Créons la boîte de base
duobox_body = create_duobox_body()

# Exporter au format STL
output_path = "/mnt/data/DuoBox_Body.stl"
duobox_body.export(output_path)

output_path
