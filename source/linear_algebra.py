from typing import List

Vector = List[float]

height_weight_age = [175, 68, 40]

grades = [95, 80, 75, 62]

def add(v: Vector, w: Vector) -> Vector:
    assert len(v) == len(w), "Функция add\nвекторы должны быть одинаковой длины"

    return [v_1 + w_1 for v_1, w_1 in zip(v, w)]


def substract (v: Vector, w: Vector) -> Vector:
    assert len(v) == len(w), "Функция substract\nвекторы должны быть одинаковой длины"
    
    return [v_i - w_i for v_i, w_i in zip(v, w)]


def vector_sum(vectors: List[Vector]) -> Vector:
    assert vectors, "Векторы не предоставлены!"

    num_elem = len(vectors[0])
    assert all(len(v) == num_elem for v in vectors), "разные векторы"

    return [sum(vector[i] for vector in vectors) for i in range(num_elem)]


def scalar_multiply(c: float, v: Vector) -> Vector:
    return [c * v_i for v_i in v]


def vector_mean(vectors: List[Vector]) -> Vector:
    n = len(vectors)
    return scalar_multiply(1/n, vector_sum(vectors))


def dot(v: Vector, w: Vector) -> float:
    assert len(v) == len(w), "Векторы должны иметь одинаковую длину"
    return sum(v_i * w_i for v_i, w_i in zip(v, w))
    

print(vector_mean([[1, 2, 3], [3, 4, 5], [5, 6, 7], [7, 8, 9]]))