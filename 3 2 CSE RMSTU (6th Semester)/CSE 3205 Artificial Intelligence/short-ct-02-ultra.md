**Q1 — Neuron & Mathematical Model**

Neuron = basic unit of nervous system. Takes inputs, computes weighted sum, applies activation.

`net = Σ(wᵢxᵢ) + b` → `y = φ(net)`

| Biological | Artificial |
|---|---|
| Dendrites | Inputs |
| Synapse | Weights |
| Soma | Summation |
| Axon | Output |

---

**Q2 — Pattern Recognition Approaches**

1. **Statistical** — Bayes' theorem, probability-based
2. **Syntactic** — Grammar/rules, structural patterns
3. **Neural Network** — Learns from data, handles complex patterns

---

**Q3 — Types of Knowledge for ANN**

1. **Prior** — Domain expertise, architecture design
2. **Training** — Labeled examples, backprop
3. **Heuristic** — Rules of thumb (small LR, random init)
4. **Structural** — Network topology (layers, connections)

---

**Q4 — Learning & Reinforcement Learning**

**Learning:** System improves performance through experience.

**RL:** Agent interacts with environment, gets reward/penalty, updates policy to maximize cumulative reward. Ex: AlphaGo, robotics.

---

**Q5 — Supervised, Unsupervised, RL**

| | Supervised | Unsupervised | RL |
|---|---|---|---|
| Data | Labeled | Unlabeled | None |
| Goal | X→Y | Find patterns | Max reward |
| Example | Spam filter | Clustering | AlphaGo |

---

**Q6 — Supervised vs Unsupervised**

| Feature | Supervised | Unsupervised |
|---|---|---|
| Data | Labeled (X,Y) | Unlabeled |
| Feedback | Direct error | None |
| Task | Classification | Clustering |

---

**Q7 — Brain vs Digital Computer**

Brain advantages: massive parallelism, ~20W energy, <100ms face recognition, fault tolerant.
Computer advantages: fast arithmetic, exact memory.
Brain wins on perception; computer wins on calculation.

---

**Q8 — Z without transfer function**

```
Y₁ = 0.6×17 + 0.3×7 = 12.3
Y₂ = 0.1×12 = 1.2
Z  = 0.60×12.3 + 0.45×1.2 = 7.92
```
**Z = 7.92**

---

**Q9 — Z with threshold (≤5→0, >5→1)**

| Neuron | Value | Output |
|---|---|---|
| Y₁ | 12.3 | 1 |
| Y₂ | 1.2 | 0 |
| Z | 0.60 | **0** |

**Z = 0**

---

**Q10 — Z with sigmoid**

```
φ(Y₁) = 1/(1+e⁻¹²·³) ≈ 1.000
φ(Y₂) = 1/(1+e⁻¹·²)  ≈ 0.769
Z_raw = 0.60×1.000 + 0.45×0.769 = 0.946
φ(Z)  = 1/(1+e⁻⁰·⁹⁴⁶) ≈ 0.720
```
**Z ≈ 0.720**

---

**Q11 — Z with MSE**

MSE is a loss function: `E = (1/2)(d − y)²`

1. Compute Z same as Q8 → Z = 7.92
2. Apply: `E = (1/2)(d − 7.92)²` where d = target from diagram

---

**Q12 — Burglary ⊥ Earthquake?**

**Yes.** Both are root nodes, no connecting path.

P(B∧E) = 0.001 × 0.002 = **0.000002** = P(B)×P(E) ✓

---

**Q13 — P(A, ¬B, ¬E, J, M)**

```
= 0.90 × 0.70 × 0.001 × 0.999 × 0.998 ≈ 0.00062
```

---

**Q14 — P(A, B, ¬E, J, M)**

```
= 0.90 × 0.70 × 0.94 × 0.001 × 0.998 ≈ 0.000591
```
