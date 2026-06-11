I'll give compact answers for all 14 questions in order.

---

**Q1 — Define neuron. Describe the mathematical model.**

A **neuron** is the basic unit of a neural network. Biological neuron: dendrites→soma→axon. Artificial equivalent: inputs→weighted sum→activation→output.

**Math model:**
- Stage 1: `net = Σ(wᵢxᵢ) + b`
- Stage 2: `y = φ(net)`

| Biological | Artificial |
|---|---|
| Dendrites | Inputs xᵢ |
| Synapse | Weights wᵢ |
| Soma | Summation Σ |
| Axon | Output y |
| Threshold | Activation φ |

---

**Q2 — Classification approaches to pattern recognition.**

Three approaches:

1. **Statistical** — Uses Bayes' theorem; P(class|X) ∝ P(X|class)×P(class). Good for numeric data.
2. **Syntactic** — Uses formal grammars/rules. Good for hierarchical/sequential patterns.
3. **Neural Network** — Learns from data via backprop. Best for images, speech, text.

---

**Q3 — Types of knowledge to build a neural network.**

| # | Type | Examples |
|---|---|---|
| 1 | Prior/Domain | Architecture choice, layer types |
| 2 | Training | Labeled examples, backpropagation |
| 3 | Heuristic | Small LR, random init, early stopping |
| 4 | Structural | Feed-forward, recurrent, convolutional |

---

**Q4 — What is learning? Short note on reinforcement learning.**

**Learning:** A system improves performance on task T through experience E (Mitchell, 1997).

**Reinforcement Learning:** Agent takes actions in an environment, receives rewards/penalties, and updates its policy to maximize cumulative reward.

- Components: Agent, Environment, State(s), Action(a), Reward(r), Policy(π)
- Examples: AlphaGo, self-driving cars, robotics

---

**Q5 — Learning? Describe RL, supervised, unsupervised.**

**Learning:** Improving performance through experience.

| Feature | Supervised | Unsupervised | Reinforcement |
|---|---|---|---|
| Data | Labeled (X,Y) | Unlabeled (X) | No fixed dataset |
| Goal | X→Y mapping | Find structure | Maximize reward |
| Feedback | Immediate error | None | Delayed reward |
| Example | Spam filter | Clustering | AlphaGo |

---

**Q6 — Distinguish supervised vs unsupervised learning.**

| Feature | Supervised | Unsupervised |
|---|---|---|
| Data | Labeled (X,Y) | Unlabeled (X) |
| Goal | Learn X→Y | Discover patterns |
| Feedback | Direct error | None |
| Tasks | Classification, Regression | Clustering, PCA |
| Example | Image classification | Customer segmentation |

---

**Q7 — What is brain? Is it faster than digital computers?**

The brain has ~86 billion neurons with ~100 trillion connections.

**Brain advantages:**
- **Massive parallelism** — billions of neurons fire simultaneously
- **Energy efficiency** — ~20W vs megawatts for supercomputers
- **Pattern recognition** — recognizes faces in <100ms
- **Fault tolerance** — adapts when neurons die

**Computer advantages:** arithmetic speed, exact recall.

Brain wins on perception and intelligence; computer wins on raw calculation.

---

**Q8 — Compute Z without transfer function.**

Given: X₁=17, X₂=7, X₃=12; W₁=0.6, W₂=0.3, W₃=0.1; v₁=0.60, v₂=0.45

```
Y₁ = 0.6×17 + 0.3×7 = 10.2 + 2.1 = 12.3
Y₂ = 0.1×12 = 1.2
Z  = 0.60×12.3 + 0.45×1.2 = 7.38 + 0.54 = 7.92
```
**Z = 7.92**

---

**Q9 — Z with threshold function (≤5→0, else→1).**

Using raw values from Q8:

| Neuron | Raw | Check | Output |
|---|---|---|---|
| Y₁ | 12.3 | 12.3 > 5 | **1** |
| Y₂ | 1.2 | 1.2 ≤ 5 | **0** |
| Z | 0.60×1 + 0.45×0 = 0.60 | 0.60 ≤ 5 | **0** |

**Z = 0**

---

**Q10 — Z with sigmoid function.**

φ(x) = 1/(1+e⁻ˣ)

```
φ(Y₁) = 1/(1+e⁻¹²·³) ≈ 1.000
φ(Y₂) = 1/(1+e⁻¹·²)  ≈ 0.7685
Z_raw  = 0.60×1.000 + 0.45×0.7685 = 0.9458
φ(Z)   = 1/(1+e⁻⁰·⁹⁴⁵⁸) ≈ 0.720
```
**Z ≈ 0.720**

---

**Q11 — Z with MSE function.**

MSE is a **loss function**, not an activation. Formula: `E = (1/2)(d − y)²`

Steps:
1. Compute Z without activation (same as Q8) → Z = 7.92 (6th/4th sem) or Z = v×H (7th/5th sem)
2. Apply MSE: `E = (1/2)(d − Z)²` where d = desired output from diagram

Report both Z and E.

---

**Q12 — Are Burglary and Earthquake independent? Justify.**

**Yes, they are marginally independent.**

- **Structural:** Both B and E are root nodes with no connecting path in the DAG.
- **Mathematical:** P(B∧E) = P(B)×P(E) → 0.001×0.002 = **0.000002** ✓

*Note: Once Alarm is observed, B and E become dependent ("explaining away").*

---

**Q13 — P(Alarm, no Burglary, no Earthquake, John and Mary call).**

P(J∧M∧A∧¬B∧¬E) = P(J|A) × P(M|A) × P(A|¬B,¬E) × P(¬B) × P(¬E)

```
= 0.90 × 0.70 × 0.001 × 0.999 × 0.998
≈ 0.00062
```
**≈ 0.00062**

---

**Q14 — P(Alarm, Burglary, no Earthquake, John and Mary call).**

P(J∧M∧A∧B∧¬E) = P(J|A) × P(M|A) × P(A|B,¬E) × P(B) × P(¬E)

```
= 0.90 × 0.70 × 0.94 × 0.001 × 0.998
≈ 0.000591
```
**≈ 0.000591**

*Q14 > Q13 in alarm probability (0.94 vs 0.001), but Q13 > Q14 overall because P(¬B)=0.999 >> P(B)=0.001.*
