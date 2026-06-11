# Neural Networks & Bayesian Networks — Exam Study Notes
### AI Question Bank Coverage: 4th, 5th, 6th, 7th Semester (Mid & Final Exam)
> **Primary Reference:** *Artificial Intelligence: A Modern Approach* — Russell & Norvig  
> **Lecture Slides:** `06-bayesian-networks.pdf` (Jean Claude Latombe / Hwee Tou Ng)

---

## Table of Contents

### Part A — Neural Networks
1. [Biological Neuron vs Artificial Neuron](#1-biological-neuron-vs-artificial-neuron)
2. [Mathematical Model of a Neuron](#2-mathematical-model-of-a-neuron)
3. [ANN Architecture (Layers & Structure)](#3-ann-architecture-layers--structure)
4. [Activation / Transfer Functions](#4-activation--transfer-functions)
5. [Compute Z — Exam Problems Fully Solved](#5-compute-z--exam-problems-fully-solved)
   - Part i: Without Transfer Function
   - **Part ii: With Threshold Function — 4th Sem Q5(d)-ii *(Solved Separately)***
   - Part iii: With Sigmoid Function
6. [Types of Learning](#6-types-of-learning)
7. [Neural Network Quick-Reference](#7-neural-network-quick-reference)

### Part B — Bayesian Networks
8. [What is a Bayesian Network?](#8-what-is-a-bayesian-network)
9. [Architecture / Structure (DAG + CPTs)](#9-architecture--structure-dag--cpts)
10. [The Burglary–Alarm Example](#10-the-burglaryalarm-example)
11. [Joint Probability Calculation](#11-joint-probability-calculation)
12. [Independence Rules Encoded in a BN](#12-independence-rules-encoded-in-a-bn)
13. [Constructing a Bayesian Network](#13-constructing-a-bayesian-network)
14. [Querying the BN (Inference)](#14-querying-the-bn-inference)
15. [Bayesian Network Quick-Reference](#15-bayesian-network-quick-reference)

### Appendix
16. [All Exam Questions — Both Topics](#16-all-exam-questions--both-topics)
17. [Key Terminology Glossary](#17-key-terminology-glossary)
18. [References](#18-references)

---

# PART A — NEURAL NETWORKS

---

## 1. Biological Neuron vs Artificial Neuron

> **Exam Questions Covered Here:**
> - 7th Sem Q5(a), Q6(b): *"Define neuron. Describe the mathematical model of an artificial neural network."*
> - 6th Sem Q6(a): *"What do you mean by neuron of human brain? Describe the mathematical model of a neuron."*
> - 5th Sem Q5(b): *"Define neuron. Describe the mathematical model of a neuron."*
> - 4th Sem Q5(c): *"Define neuron. Describe the mathematical model of a neuron."*

### 1.1 Biological Neuron

The human brain contains about **86 billion neurons**, each connected to thousands of others. A biological neuron has:
<img width="415" height="220" alt="image" src="https://github.com/user-attachments/assets/a39b31e4-a0a2-430f-b4d4-183c51e8ad6e" />
```
        Dendrites                    Axon Terminals
        (inputs)                     (outputs)
           │                              │
    ───────▼──────────────────────────────▼───────
    │  Dendrites ──► Cell Body (Soma) ──► Axon  │
    ──────────────────────────────────────────────
```

| Biological Part | Function | ANN Equivalent |
|-----------------|----------|----------------|
| Dendrites | Receive incoming signals | Input values (x₁, x₂, ..., xₙ) |
| Synapse | Strength of connection between neurons | Weights (w₁, w₂, ..., wₙ) |
| Cell Body (Soma) | Accumulates and processes signals | Summation function (Σ) |
| Axon | Transmits output to next neuron | Output signal (y) |
| Threshold | Decides whether neuron fires | Activation function φ(.) |

> *"A negative weight reflects an inhibitory connection, while positive values designate excitatory connections."*

### 1.2 Biological vs Artificial — Key Differences

| Feature | Biological Neuron | Artificial Neuron |
|---------|-------------------|-------------------|
| Speed | ~200 Hz (slow electrochemical) | GHz (very fast electronic) |
| Learning | Synaptic plasticity | Weight adjustment (backprop) |
| Fault tolerance | Very high | Moderate |
| Parallelism | ~10¹⁴ connections | Simulated in software |
| Energy | Very low (~20W for whole brain) | High (GPU-dependent) |

---

## 2. Mathematical Model of a Neuron

> **Exam Questions Covered Here:**
> - 7th Sem Q5(a): *"Define neuron. Describe the mathematical model of a neuron."*
> - 7th Sem Q6(b): *"Define neuron. Describe the mathematical model of artificial neural network."*
> - 6th Sem Q6(a): *"Describe the mathematical model of a neuron."*
> - 5th Sem Q5(b): *"Define neuron. Describe the mathematical model of a neuron."*
> - 4th Sem Q5(c): *"Define neuron. Describe the mathematical model of a neuron."*

### 2.1 Structure of a Single Artificial Neuron


```
  x₁ ──[w₁]──┐
              │
  x₂ ──[w₂]──┤
              ├──→ [ Σ wᵢxᵢ + b ] ──→ [ φ(net) ] ──→ Output y
  x₃ ──[w₃]──┤
              │
  xₙ ──[wₙ]──┘
              ↑
           Bias b (optional)
```

**Legend:**
- `x₁, x₂, ..., xₙ` = Input signals
- `w₁, w₂, ..., wₙ` = Synaptic weights
- `b` = Bias term (shifts activation threshold)
- `Σ` = Summation junction (linear combiner)
- `φ(.)` = Activation / transfer function
- `y` = Output signal

### 2.2 Mathematical Equations

**Step 1 — Compute Weighted Sum (net input):**
```
net = Σᵢ (wᵢ × xᵢ) + b
    = w₁x₁ + w₂x₂ + ... + wₙxₙ + b
```

**Step 2 — Apply Activation Function:**
```
y = φ(net)
```

**Full combined formula:**
```
y = φ( Σᵢ wᵢxᵢ + b )
```

### 2.3 Two-Layer (Multi-Layer) Network Notation

For a network with hidden layer neurons Y and output Z:

```
Hidden neuron Yⱼ :   Yⱼ = φ( Σᵢ wᵢⱼ × xᵢ )
Output neuron Z  :   Z  = φ( Σⱼ vⱼ  × Yⱼ )
```

Where `vⱼ` = weights from hidden layer to output neuron.

---

## 3. ANN Architecture (Layers & Structure)
Artificial Neural Networks (ANN)

> **Exam Questions Covered Here:**
> - 7th Sem Q5(b): *"Discuss the classification approaches to pattern recognition."*
> - 7th Sem Q5(c): *"Discuss about various types of knowledge to build a neural network."*
> - 5th Sem Q6(c): *"What is brain? It is faster than the fastest digital computer. Explain with example."*

### 3.1 Standard Feed-Forward Neural Network
<img width="1024" height="399" alt="image" src="https://github.com/user-attachments/assets/8d1a8ad8-0107-41d0-ba80-ce3753e5cbf3" />

```
 INPUT LAYER        HIDDEN LAYER        OUTPUT LAYER
 ───────────        ────────────        ────────────
    x₁ ─────────────► H₁ ──────────┐
        ╲           ╱    ╲          │
         ╲         ╱      ╲         ▼
    x₂ ───╲───────╱─────► H₂ ────► Z (output)
         ╱  ╲           ╱         ▲
        ╱    ╲         ╱          │
    x₃ ───────╲───────╱────────► H₃ ─┘

   [Input]         [Hidden]        [Output]
```


### 3.2 Layer Descriptions

| Layer | Role | Notes |
|-------|------|-------|
| **Input Layer** | Receives raw features; no computation done here | One neuron per input variable |
| **Hidden Layer(s)** | Learns internal representations and patterns | Number configurable |
| **Output Layer** | Produces final result/prediction | One neuron per output |

### 3.3 Exact Exam Network — (X1, X2, X3 → Y1, Y2 → Z)

This is the specific network used in **6th Sem Q6(b)** and **4th Sem Q5(d)**:

```
X₁(17) ──[W₁=0.6]──┐
                     ├──► [Y₁] ──[v₁=0.60]──┐
X₂(7)  ──[W₂=0.3]──┘                        ├──► [Z]
                                              │
X₃(12) ──[W₃=0.1]────────► [Y₂] ──[v₂=0.45]┘
```

- W₁, W₂, W₃ = input-to-hidden weights
- v₁, v₂ = hidden-to-output weights
- Y₁, Y₂ = hidden layer neurons
- Z = output neuron

---

## 4. Activation / Transfer Functions

> **Exam Questions Covered Here:**
> - 4th Sem Q5(d)-ii: *"Compare Z with threshold function. If value ≤5 → 0, else → 1."*
> - 4th Sem Q5(d)-iii: *"Compute Z with sigmoid transfer function used at all neurons."*
> - 6th Sem Q6(b)-ii: Same threshold question.
> - 6th Sem Q6(b)-iii: Same sigmoid question.
> - 7th Sem Q6(c)-ii, 5th Sem Q5(c)-ii: *"Compute Z with MSE function E used at all neurons."*

### 4.1 Threshold (Step) Function

```
         1 │              ┌──────────────
           │              │
         0 │──────────────┘
           └──────────────────────────── net
                       threshold (θ)

φ(net) = 1   if net ≥ θ
φ(net) = 0   if net < θ
```
<img width="3000" height="2000" alt="image" src="https://github.com/user-attachments/assets/293ce485-ee85-4ee3-90a0-ee3d006723b1" />
<img width="1267" height="906" alt="image" src="https://github.com/user-attachments/assets/b5cedb25-a26a-43c9-8a7d-9f90ec4c084f" />

**Exam:** "If value is 5 or less → output 0, otherwise → output 1" means θ = 5.

### 4.2 Sigmoid Function
<img width="856" height="554" alt="image" src="https://github.com/user-attachments/assets/05e18e7a-59dd-42de-b7d1-a1be7887e573" />

```
         1 │                 ─────────────
           │               /
        0.5│              /
           │             /
         0 │────────────/─────────────── net
                        0

φ(net) = 1 / (1 + e^(−net))    Range: (0, 1)
```

Used when smooth, differentiable output in range (0,1) is needed.

### 4.3 Linear / Identity Function

```
φ(net) = net    (output = input, no transformation)
```
<img width="792" height="612" alt="image" src="https://github.com/user-attachments/assets/35884aa7-aff7-4887-bfea-3be6299a416e" />
<img width="800" height="400" alt="image" src="https://github.com/user-attachments/assets/0b578e4c-b61e-4134-a529-e7f6327cef2b" />
<img width="1280" height="720" alt="image" src="https://github.com/user-attachments/assets/4ef407b8-0078-44dc-974d-807a20c14edb" />

Used when **no transfer function** is applied — raw weighted sum is the output.

### 4.4 Mean Squared Error (MSE)

MSE is a **loss/error function**, not an activation function. It measures how wrong the network's output is.

```
E = (1/2) × (desired − actual)²      [single output, simplified]
E = (1/n) × Σ (dᵢ − yᵢ)²           [general form, n outputs]
```
<img width="1200" height="675" alt="image" src="https://github.com/user-attachments/assets/8c5f589f-30b8-4d66-a673-be9a60f2f5a9" />

**Exam note:** "Compute Z with MSE used at all neurons" means compute raw Z first (no activation), then report:
```
E = (1/2)(d − Z)²
```
where `d` = desired/target output.

---

## 5. Compute Z — Exam Problems Fully Solved

> **Exam Questions Covered Here:**
> - 6th Sem Q6(b): X1=17, X2=7, X3=12; W1=0.6, W2=0.3, W3=0.1; v1=0.6, v2=0.45
> - 4th Sem Q5(d): Same values as above
> - 7th Sem Q6(c): x=1, y=1 (weights from diagram)
> - 5th Sem Q5(c): x=1, y=1 (weights from diagram)

---

### Problem A — 6th Sem Q6(b) / 4th Sem Q5(d)

**Given:**
```
X₁ = 17,  X₂ = 7,  X₃ = 12
W₁ = 0.6, W₂ = 0.3, W₃ = 0.1
v₁ (Y₁ → Z weight) = 0.60
v₂ (Y₂ → Z weight) = 0.45
```

**Network diagram:**
```
X₁(17) ──[0.6]──┐
                  ├──► Y₁ ──[0.60]──┐
X₂(7)  ──[0.3]──┘                   ├──► Z
                                      │
X₃(12) ──[0.1]────────► Y₂ ──[0.45]─┘
```

---

#### Part (i): Z WITHOUT transfer function (raw weighted sum)

**Compute Y₁:**
```
Y₁ = W₁×X₁ + W₂×X₂
   = (0.6 × 17) + (0.3 × 7)
   = 10.2 + 2.1
   = 12.3
```

**Compute Y₂:**
```
Y₂ = W₃ × X₃
   = 0.1 × 12
   = 1.2
```

**Compute Z:**
```
Z = v₁×Y₁ + v₂×Y₂
  = (0.60 × 12.3) + (0.45 × 1.2)
  = 7.38 + 0.54
  = 7.92
```

> **Answer (i): Z = 7.92**

---

#### Part (ii): Z WITH Threshold Function — 4th Sem Q5(d)-ii *(Solved Separately)*

> **Exam Question (4th Sem Q5(d)-ii / 6th Sem Q6(b)-ii):**
> *"Compare the value of Z with a threshold function. If the value is 5 or less → output 0, otherwise → output 1."*

---

**Threshold (Step) Function Rule:**
```
φ(net) = 0    if  net ≤ 5   (threshold θ = 5)
φ(net) = 1    if  net > 5
```

**Given values (from Part i):**
```
Y₁ raw = 12.3    (computed in Part i)
Y₂ raw = 1.2     (computed in Part i)
```

---

**Step 1 — Apply Threshold to Hidden Neuron Y₁:**
```
Y₁_raw = 12.3

Check: Is 12.3 ≤ 5?  →  NO  (12.3 > 5)

∴  φ(Y₁) = 1
```

**Step 2 — Apply Threshold to Hidden Neuron Y₂:**
```
Y₂_raw = 1.2

Check: Is 1.2 ≤ 5?  →  YES  (1.2 ≤ 5)

∴  φ(Y₂) = 0
```

**Step 3 — Compute Raw Weighted Sum at Output Neuron Z:**
```
Z_raw = v₁ × φ(Y₁) + v₂ × φ(Y₂)
      = (0.60 × 1) + (0.45 × 0)
      = 0.60 + 0.00
      = 0.60
```

**Step 4 — Apply Threshold to Output Neuron Z:**
```
Z_raw = 0.60

Check: Is 0.60 ≤ 5?  →  YES  (0.60 ≤ 5)

∴  φ(Z) = 0
```

---

**Summary Table:**

| Neuron | Raw Value | Condition | Threshold Output |
|--------|-----------|-----------|-----------------|
| Y₁     | 12.3      | 12.3 > 5  | **1**           |
| Y₂     | 1.2       | 1.2 ≤ 5   | **0**           |
| Z      | 0.60      | 0.60 ≤ 5  | **0**           |

> **✅ Answer (ii): Z = 0**
>
> *The final output Z after applying the threshold function (θ = 5) at all neurons is **0**.*

---

#### Part (iii): Z WITH Sigmoid Function φ(x) = 1 / (1 + e⁻ˣ)

Apply sigmoid at each neuron:

**Y₁ sigmoid:**
```
Y₁ = 1 / (1 + e^(−12.3))
   = 1 / (1 + 0.0000045)
   ≈ 0.9999955  ≈ 1.000
```

**Y₂ sigmoid:**
```
Y₂ = 1 / (1 + e^(−1.2))
   = 1 / (1 + 0.3012)
   = 1 / 1.3012
   ≈ 0.7685
```

**Z raw:**
```
Z_raw = (0.60 × 1.000) + (0.45 × 0.7685)
      = 0.600 + 0.3458
      = 0.9458
```

**Z sigmoid:**
```
Z = 1 / (1 + e^(−0.9458))
  = 1 / (1 + 0.3885)
  = 1 / 1.3885
  ≈ 0.720
```

> **Answer (iii): Z ≈ 0.720**

---

### Problem B — 7th Sem Q6(c) / 5th Sem Q5(c) (x=1, y=1)

**Given:** x = 1, y = 1. Weights are read from the diagram provided in the exam.

**General procedure (apply for any weights given in diagram):**

**Part (i) — Without transfer function:**
```
Step 1: H = w₁×x + w₂×y         (read w₁, w₂ from diagram)
Step 2: Z = v × H                 (read v from diagram)
Result: Z = raw weighted sum (no activation)
```

**Part (ii) — With MSE function E at all neurons:**
```
Step 1: Compute raw Z from part (i) above
Step 2: Apply MSE formula:
        E = (1/2) × (d − Z)²
        where d = desired/target output value
Step 3: Report Z and E
```

> **Tip:** If no desired output `d` is given in the diagram, compute only Z from part (i) and state the MSE formula.

---

## 6. Types of Learning

> **Exam Questions Covered Here:**
> - 7th Sem Q5(d): *"What do you mean by learning? Write short note about reinforcement learning."*
> - 6th Sem Q6(c): *"What do you mean by learning? Describe reinforcement learning, supervised learning and unsupervised learning with proper example."*
> - 5th Sem Q5(d): *"What do you mean by learning? Write short note about reinforcement learning."*
> - 5th Sem Q6(b): *"Distinguish between supervised learning and unsupervised learning."*

### 6.1 What is Learning?

Learning in AI = the ability of a system to **improve its performance** on tasks through experience, **without being explicitly reprogrammed**.

### 6.2 Three Types of Machine Learning

```
                    MACHINE LEARNING
                          │
           ┌──────────────┼──────────────┐
           ▼              ▼              ▼
      Supervised      Unsupervised   Reinforcement
       Learning         Learning       Learning
    (labeled data)  (unlabeled data) (reward/penalty)
```

---

#### (a) Supervised Learning

| Feature | Detail |
|---------|--------|
| **Data** | Labeled input-output pairs (X, Y) |
| **Goal** | Learn mapping: input X → output Y |
| **Feedback** | Direct — error between predicted and actual output |
| **Examples** | Spam detection, image classification, house price prediction |

```
Training Data:  (X₁,Y₁), (X₂,Y₂), ..., (Xₙ,Yₙ)
                        ↓
               Model learns f: X → Y
                        ↓
          New input X_new → Predict Y_new
```
<img width="800" height="400" alt="image" src="https://github.com/user-attachments/assets/8c5b5740-fa40-4ce7-96ce-feae71f081c0" />
<img width="273" height="185" alt="image" src="https://github.com/user-attachments/assets/c11a8653-a51d-4e7d-8fdf-48f8c99322e1" />

**Analogy:** Learning from a textbook with an answer key — the teacher provides correct labels for every example.

---

#### (b) Unsupervised Learning

| Feature | Detail |
|---------|--------|
| **Data** | Unlabeled — no output labels provided |
| **Goal** | Find hidden patterns, clusters, or structure |
| **Feedback** | None — no ground truth |
| **Examples** | Customer segmentation, anomaly detection, dimensionality reduction |

```
Unlabeled Data: X₁, X₂, X₃, ..., Xₙ
                        ↓
         Algorithm discovers structure
                        ↓
          Clusters / Patterns / Groups
```
<img width="800" height="400" alt="image" src="https://github.com/user-attachments/assets/462431a5-279e-44f7-b278-88ef78999ea1" />

**Analogy:** Sorting unknown seashells into groups by shape — no guide, just observed similarity.

---

#### (c) Reinforcement Learning

| Feature | Detail |
|---------|--------|
| **Data** | No fixed dataset — learns from environment interaction |
| **Goal** | Maximize cumulative reward over time |
| **Feedback** | Reward (+) or Penalty (−) after each action |
| **Examples** | Game-playing AI (Chess, Go), robotics, self-driving cars |
<img width="1200" height="628" alt="image" src="https://github.com/user-attachments/assets/2142a504-527c-4ad7-ae50-05f78217478d" />
<img width="1748" height="1240" alt="image" src="https://github.com/user-attachments/assets/98887422-24de-4496-82b1-b0f6103c6a59" />
<img width="1200" height="609" alt="image" src="https://github.com/user-attachments/assets/ff73c180-f0aa-4576-b403-32e41bc55e5c" />

```
        ┌──────────────────────────────────────┐
        │                                      │
        ▼                                      │
   ┌─────────┐   Action a    ┌─────────────┐  │
   │  Agent  │ ────────────► │ Environment │  │
   └─────────┘               └─────────────┘  │
        ▲                          │           │
        │    State s + Reward r    │           │
        └──────────────────────────┘           │
                                               │
        Agent updates policy ──────────────────┘
```

**Key terms:**
| Term | Meaning |
|------|---------|
| Agent | The learner / decision-maker |
| Environment | What the agent interacts with |
| State (s) | Current situation of the agent |
| Action (a) | What the agent does |
| Reward (r) | Feedback — positive for good action, negative for bad |
| Policy (π) | Strategy: maps states → actions |

**Analogy:** Training a dog — give a treat for good behaviour, scold for bad. The dog learns to repeat rewarded actions.

---

### 6.3 Comparison Table

| Feature | Supervised | Unsupervised | Reinforcement |
|---------|-----------|--------------|---------------|
| Data type | Labeled (X, Y) | Unlabeled (X only) | No fixed dataset |
| Output | Predefined labels | Discovered structure | Cumulative reward |
| Feedback | Immediate error signal | None | Delayed reward/penalty |
| Task type | Classification, Regression | Clustering, Association | Sequential decisions |
| Example algorithms | Neural Net, SVM, Decision Tree | K-Means, PCA | Q-Learning, DQN |
| Real example | Email spam filter | Customer segmentation | Chess-playing AlphaGo |

---

## 7. Neural Network Quick-Reference

| Formula | Meaning |
|---------|---------|
| `net = Σ(wᵢ × xᵢ) + b` | Weighted input sum at a neuron |
| `y = φ(net)` | Output after activation function |
| `Sigmoid: φ(x) = 1/(1 + e⁻ˣ)` | Smooth output in (0,1) |
| `Threshold: φ(x) = 1 if x≥θ, else 0` | Binary step output |
| `MSE: E = (1/2)(d − y)²` | Loss/error function |
| `Y₁ = W₁X₁ + W₂X₂` | Hidden neuron (no activation) |
| `Z = v₁Y₁ + v₂Y₂` | Output neuron (no activation) |
| `Z_sigmoid = 1/(1 + e^−Z_raw)` | Z after sigmoid |

---
<img width="1001" height="471" alt="image" src="https://github.com/user-attachments/assets/bc8041c9-4b6f-4c58-b8ff-c5196b3c8fdb" />

---

# PART B — BAYESIAN NETWORKS

---

## 8. What is a Bayesian Network?

> **Exam Questions Covered Here:**
> - 5th Sem Q6(d): *"A Bayesian network showing topology and CPTs... determine probabilities."*
> - 4th Sem Q6(d): *"A Bayesian network showing topology and CPTs... determine probabilities."*
> - 5th Sem Q6(i): *"Are Burglary and Earthquake independent? Justify."*

A **Bayesian Network (BN)** is a probabilistic graphical model that represents variables and their conditional dependencies using a **Directed Acyclic Graph (DAG)**.


> *"A simple, graphical notation for conditional independence assertions and hence for compact specification of full joint distributions."*  
> — Slide 7, `06-bayesian-networks.pdf`

### Why BNs?

- A belief state with **n propositions** needs **2ⁿ entries** in a full joint table → expensive.
- BNs exploit **conditional independence** to store far fewer numbers.
- Example: Burglary–Alarm uses **10 numbers** instead of **31** (full joint for 5 variables).

---

## 9. Architecture / Structure (DAG + CPTs)

> **Exam Questions Covered Here:**
> - All Bayesian Network questions require understanding of DAG + CPT structure.

### 9.1 Components

| Component | Description |
|-----------|-------------|
| **Node** | One per random variable |
| **Directed Edge (arc)** | "X directly influences Y" — causal relationship |
| **CPT** | Conditional Probability Table: P(X \| Parents(X)) |
| **Root node** | No parents → stores prior probability P(X) |
| **Child node** | Has parents → stores conditional P(X \| Parents) |

> **Key rule:** A node with **k parents** has a CPT of **2ᵏ rows**.

### 9.2 General BN Architecture
<img width="800" height="400" alt="image" src="https://github.com/user-attachments/assets/b591a6ea-d368-4e55-ab24-5f40a9cb3d80" />

```
         ┌─────────┐        ┌──────────┐
         │ Node A  │        │  Node B  │
         │ (Root)  │        │  (Root)  │
         │  P(A)   │        │   P(B)   │
         └────┬────┘        └────┬─────┘
              │                  │
              └────────┬─────────┘
                       ▼
                 ┌──────────┐
                 │  Node C  │
                 │P(C|A, B) │   ← CPT: 2² = 4 rows
                 └──────┬───┘
                        │
             ┌──────────┴──────────┐
             ▼                     ▼
       ┌──────────┐         ┌──────────┐
       │  Node D  │         │  Node E  │
       │  P(D|C)  │         │  P(E|C)  │
       └──────────┘         └──────────┘
```

### 9.3 Simple Example — Cavity Network (3 nodes)

```
         ┌──────────┐
         │  Cavity  │   P(Cavity) = 0.2
         └──────────┘
          /          \
         ▼            ▼
  ┌───────────┐  ┌─────────┐
  │ Toothache │  │  Catch  │
  │ P(T|Cav)  │  │ P(C|Cav)│
  └───────────┘  └─────────┘
```

| Cavity | P(Toothache \| Cavity) | P(Catch \| Cavity) |
|--------|------------------------|---------------------|
| T | 0.6 | 0.9 |
| F | 0.1 | 0.02 |

> Toothache ⊥ Catch \| Cavity — 5 numbers instead of 7. *(Slide 9, PDF)*

---

## 10. The Burglary–Alarm Example

> **Exam Questions Covered Here:**
> - 5th Sem Q6(d)-i,ii,iii: Independence + joint probability calculations
> - 4th Sem Q6(d)-i,ii,iii: Same calculations

### 10.1 Problem

> *"I'm at work; neighbor John calls to say my alarm is ringing. Sometimes it's set off by minor earthquakes. Is there a burglar?"*  
> — Slide 10, `06-bayesian-networks.pdf`

### 10.2 Variables

| Variable | Abbr. | Meaning |
|----------|-------|---------|
| Burglary | B | A burglar breaks in |
| Earthquake | E | Minor earthquake occurs |
| Alarm | A | Alarm goes off |
| JohnCalls | J | John calls the owner |
| MaryCalls | M | Mary calls the owner |

### 10.3 Network Architecture (DAG)
<img width="640" height="480" alt="image" src="https://github.com/user-attachments/assets/a8c39e04-b070-41e9-9e09-9c88e7af0278" />
```
    ┌───────────┐              ┌────────────┐
    │ Burglary  │              │ Earthquake │
    │  P(B)     │              │   P(E)     │
    │ = 0.001   │              │ = 0.002    │
    └─────┬─────┘              └──────┬─────┘
          │                           │
          └─────────────┬─────────────┘
                        ▼
                 ┌─────────────┐
                 │    Alarm    │
                 │  P(A|B, E)  │  ← 2² = 4 rows in CPT
                 └──────┬──────┘
                        │
           ┌────────────┴────────────┐
           ▼                         ▼
    ┌─────────────┐           ┌─────────────┐
    │  JohnCalls  │           │  MaryCalls  │
    │   P(J|A)    │           │   P(M|A)    │
    └─────────────┘           └─────────────┘
```

> *Directed Acyclic Graph — no cycles allowed.* *(Slide 11, PDF)*

### 10.4 All CPT Values

**Prior probabilities (root nodes):**
```
P(B)  = 0.001       P(¬B) = 0.999
P(E)  = 0.002       P(¬E) = 0.998
```

**P(Alarm | Burglary, Earthquake):**

| B | E | P(A \| B,E) |
|---|---|-------------|
| T | T | **0.95** |
| T | F | **0.94** |
| F | T | **0.29** |
| F | F | **0.001** |

**P(JohnCalls | Alarm):**

| A | P(J \| A) |
|---|-----------|
| T | **0.90** |
| F | **0.05** |

**P(MaryCalls | Alarm):**

| A | P(M \| A) |
|---|-----------|
| T | **0.70** |
| F | **0.01** |

> Total: **10 values** instead of 2⁵ − 1 = **31**. *(Slide 12, PDF)*

---

## 11. Joint Probability Calculation

> **Exam Questions Covered Here:**
> - 5th Sem Q6(d)-ii: *P(Alarm, no Fire, no Earthquake, both John & Mary call)*
> - 5th Sem Q6(d)-iii: *P(Alarm, Fire, no Earthquake, both John & Mary call)*
> - 4th Sem Q6(d)-ii,iii: Same questions

### 11.1 General Formula

$$P(X_1, X_2, \ldots, X_n) = \prod_{i=1}^{n} P(X_i \mid \text{Parents}(X_i))$$

---

### 11.2 Solved — P(J ∧ M ∧ A ∧ ¬B ∧ ¬E) [Exam Q-ii]

> *Alarm sounded, no Burglary, no Earthquake, both John and Mary call.*

**Step 1 — Expand using BN chain rule:**
```
P(J ∧ M ∧ A ∧ ¬B ∧ ¬E)
= P(J|A) × P(M|A) × P(A|¬B,¬E) × P(¬B) × P(¬E)
```

**Why?** From the DAG:
- J depends only on A → P(J | A, ¬B, ¬E) = P(J|A)
- M depends only on A → P(M | A, ¬B, ¬E) = P(M|A)
- B, E are independent roots → P(¬B, ¬E) = P(¬B) × P(¬E)

**Step 2 — Substitute CPT values:**
```
= 0.90 × 0.70 × 0.001 × 0.999 × 0.998
```

**Step 3 — Compute:**
```
0.90 × 0.70        = 0.630
0.630 × 0.001      = 0.000630
0.000630 × 0.999   = 0.000629
0.000629 × 0.998   ≈ 0.000628
```

> **Answer: P(J ∧ M ∧ A ∧ ¬B ∧ ¬E) ≈ 0.00062** *(Slides 18–21, PDF)*

---

### 11.3 Solved — P(J ∧ M ∧ A ∧ B ∧ ¬E) [Exam Q-iii]

> *Alarm sounded, Burglary occurred, no Earthquake, both John and Mary call.*

**Expand:**
```
P(J ∧ M ∧ A ∧ B ∧ ¬E)
= P(J|A) × P(M|A) × P(A|B=T, E=F) × P(B) × P(¬E)
= 0.90 × 0.70 × 0.94 × 0.001 × 0.998
```

**Compute:**
```
0.90 × 0.70        = 0.630
0.630 × 0.94       = 0.5922
0.5922 × 0.001     = 0.0005922
0.0005922 × 0.998  ≈ 0.000591
```

> **Answer: P(J ∧ M ∧ A ∧ B ∧ ¬E) ≈ 0.000591**

---

## 12. Independence Rules Encoded in a BN

> **Exam Questions Covered Here:**
> - 5th Sem Q6(d)-i: *"Are Burglary and Earthquake independent? Justify."*
> - 4th Sem Q6(d)-i: Same question.

### 12.1 Core Rule

> **"A node is independent of its non-descendants given its parents."**  
> *(Slide 14, PDF)*

### 12.2 Independence Facts — Burglary–Alarm Network

| Claim | T/F | Reason |
|-------|-----|--------|
| Burglary ⊥ Earthquake | ✅ True | Both are root nodes, no common parent |
| JohnCalls ⊥ MaryCalls \| Alarm | ✅ True | Both depend only on Alarm |
| Burglary ⊥ JohnCalls | ❌ False | Connected path via Alarm |
| P(J∧M\|A) = P(J\|A)×P(M\|A) | ✅ True | J and M conditionally independent given A |

### 12.3 Exam Answer — 5th Sem Q6(d)-i

**Q: If no evidence is observed, are Burglary and Earthquake independent? Justify.**

**Answer:** Yes, they are **marginally independent** because:
- There is **no directed path** between them in the DAG.
- Both are root nodes with no shared ancestor.
- Therefore: P(B, E) = P(B) × P(E) = 0.001 × 0.002 = **0.000002**

This satisfies the independence definition: **P(B ∧ E) = P(B) × P(E)**.

> **Note:** Once Alarm is observed, B and E become **dependent** — this is the **"explaining away"** effect. Observing the alarm makes burglary a more likely cause, which in turn reduces the probability of earthquake as the cause.

### 12.4 Exam Answer — 4th Sem Q6(d)-i

**Q: "If no evidence is observed, no calculation needed because probabilities of independence are high."**

This statement is **partially correct but oversimplified**. The correct answer:

Burglary and Earthquake are **structurally independent** (no connecting path in the DAG). The network topology directly encodes this — no calculation is needed to confirm independence because the graph itself shows there is no causal relationship.

---

## 13. Constructing a Bayesian Network

> **Exam Questions Covered Here:**
> - Understanding of variable ordering and BN construction (conceptual basis for all BN questions).

### 13.1 Algorithm *(Slide 23, PDF)*

```
1. Choose ordering of variables: X₁, X₂, ..., Xₙ
2. For i = 1 to n:
   a. Add Xᵢ to the network
   b. Select minimal parents from X₁...Xᵢ₋₁ such that:
      P(Xᵢ | Parents(Xᵢ)) = P(Xᵢ | X₁, ..., Xᵢ₋₁)
```

### 13.2 Effect of Variable Ordering

**Causal order** (causes before effects) → most compact network.  
**Non-causal order** → more numbers needed, harder to judge independence.

**Example — non-causal order M, J, A, B, E:** *(Slides 24–29, PDF)*

| Query | Answer | Reason |
|-------|--------|--------|
| P(J\|M) = P(J)? | **No** | J and M correlated through Alarm |
| P(A\|J,M) = P(A)? | **No** | A is parent of both J and M |
| P(B\|A,J,M) = P(B\|A)? | **Yes** | B independent of J,M given A |
| P(E\|B,A,J,M) = P(E\|A,B)? | **Yes** | E independent of J,M given A |

> Causal order needs **10 numbers**. Non-causal order needs **13 numbers**. *(Slide 29, PDF)*

---

## 14. Querying the BN (Inference)

### 14.1 Bayes' Rule on BN

```
P(C|t) = α × P(t|C) × P(C)
```

α = normalizing constant ensuring all probabilities sum to 1.

### 14.2 Marginalization

**Example — Find P(B|J):** *(Slide 32, PDF)*
```
P(b|J) = α × Σₘ Σₐ Σₑ P(b)P(e)P(a|b,e)P(J|a)P(m|a)
        = α × P(b) × Σₑ P(e) × Σₐ P(a|b,e)P(J|a) × Σₘ P(m|a)
```

Re-ordering avoids redundant computation (variable elimination).

### 14.3 Singly Connected BN

A BN is **singly connected** if there is at most one undirected path between any two nodes. *(Slide 34, PDF)*

```
    B       E
     \     /
      \   /
       \ /
        A
       / \
      J   M
```

The Burglary–Alarm network is singly connected → inference runs in **linear time** in number of CPT entries.

---

## 15. Bayesian Network Quick-Reference

| Formula | Description |
|---------|-------------|
| `P(X₁,...,Xₙ) = Πᵢ P(Xᵢ\|Parents(Xᵢ))` | Chain rule for BN |
| `P(C\|t) = α P(t\|C) P(C)` | Bayes' rule for querying |
| `CPT rows for k parents = 2ᵏ` | CPT size |
| `P(J∧M∧A∧¬B∧¬E) ≈ 0.00062` | Key exam answer |
| `P(J∧M∧A∧B∧¬E) ≈ 0.000591` | Key exam answer |
| `P(B,E) = P(B)×P(E) = 0.000002` | Independence proof |

---

---

# APPENDIX

---

## 16. All Exam Questions — Both Topics

### Neural Network Questions

#### Mid-Term

| Sem | Exam | Question |
|-----|------|----------|
| 7th | Mid 2 | — (no NN in mid) |

#### Final Exam

| Sem | Q No. | Full Question Text |
|-----|-------|--------------------|
| **7th** | Q5(a) | Define neuron. Describe the mathematical model of a neuron. **[4]** |
| **7th** | Q5(b) | Discuss the classification approaches to pattern recognition. **[4]** |
| **7th** | Q5(c) | Discuss about various types of knowledge to build a neural network. **[3]** |
| **7th** | Q5(d) | What do you mean by learning? Write short note about reinforcement learning. **[4]** |
| **7th** | Q6(b) | Define neuron. Describe the mathematical model of artificial neural network. **[part]** |
| **7th** | Q6(c)-i | Compute the value of Z without a transfer function. (x=1, y=1, weights from diagram) |
| **7th** | Q6(c)-ii | Compute the value of Z with the Mean Square Error Function E used at all neurons. |
| **6th** | Q6(a) | What do you mean by neuron of human brain? Describe the mathematical model of a neuron. **[part]** |
| **6th** | Q6(b)-i | Compute the value of Z without a transfer function. (X1=17, X2=7, X3=12, W1=0.6, W2=0.3, W3=0.1, v1=0.6, v2=0.45) |
| **6th** | Q6(b)-ii | Compare the value of Z with a threshold function. If value ≤5 → 0, else → 1. |
| **6th** | Q6(b)-iii | Compute the value of Z with the sigmoid transfer function used at all neurons. |
| **6th** | Q6(c) | What do you mean by learning? Describe reinforcement learning, supervised learning and unsupervised learning with proper example. **[5]** |
| **5th** | Q5(b) | Define neuron. Describe the mathematical model of a neuron. **[4]** |
| **5th** | Q5(c)-i | Compute the value of Z without a transfer function. (x=1, y=1) |
| **5th** | Q5(c)-ii | Compute the value of Z with the Mean Squared Error function E used at all neurons. |
| **5th** | Q5(d) | What do you mean by learning? Write short note about reinforcement learning. **[3]** |
| **5th** | Q6(b) | Distinguish between supervised learning and unsupervised learning. **[part]** |
| **5th** | Q6(c) | What is brain? It is faster than the fastest digital computer. Explain with example. **[part]** |
| **4th** | Q5(c) | Define neuron. Describe the mathematical model of a neuron. **[part]** |
| **4th** | Q5(d)-i | Compute the value of Z without a transfer function. (X1=17, X2=7, X3=12, W1=0.6, W2=0.3, W3=0.1, v1=0.6, v2=0.45) |
| **4th** | Q5(d)-ii | Compare Z with threshold function. If ≤5 → 0, else → 1. |
| **4th** | Q5(d)-iii | Compute Z with the sigmoid transfer function used at all neurons. |

---

### Bayesian Network Questions

#### Final Exam

| Sem | Q No. | Full Question Text |
|-----|-------|--------------------|
| **5th** | Q6(d)-i | If no evidence is observed, are Burglary and Earthquake independent? Justify by calculating whether probabilities satisfy the definition of conditional independence. |
| **5th** | Q6(d)-ii | Determine the probability: Alarm sounded, no Fire, no Earthquake, both John and Mary call. |
| **5th** | Q6(d)-iii | Determine the probability: Alarm sounded, Fire occurred, no Earthquake, both John and Mary call. |
| **4th** | Q6(d)-i | If no evidence is observed, then there is no need to perform calculations. Probabilities of independence are high. (Evaluate this statement.) |
| **4th** | Q6(d)-ii | Determine the probability: Alarm sounded, no Fire, no Earthquake, both John and Mary call. |
| **4th** | Q6(d)-iii | Determine the probability: Alarm sounded, Fire occurred, no Earthquake, both John and Mary call. |

---

### Answer Summary Table

| Question | Answer |
|----------|--------|
| Z without transfer function (X1=17...) | **Z = 7.92** |
| Z with threshold (θ=5) | **Z = 0** |
| Z with sigmoid | **Z ≈ 0.720** |
| P(J∧M∧A∧¬B∧¬E) | **≈ 0.00062** |
| P(J∧M∧A∧B∧¬E) | **≈ 0.000591** |
| Are B and E independent? | **Yes — P(B,E) = 0.000002 = P(B)×P(E)** |

---

## 17. Key Terminology Glossary

### Neural Network

| Term | Definition |
|------|-----------|
| **Neuron (Artificial)** | Basic computing unit; computes weighted sum then applies activation |
| **Weight (w)** | Strength of connection between neurons |
| **Bias (b)** | Extra input shifting the activation threshold |
| **Net input** | net = Σ(wᵢxᵢ) + b |
| **Activation function** | Non-linear function φ applied to net input |
| **Sigmoid** | φ(x) = 1/(1+e⁻ˣ); output in (0,1) |
| **Threshold function** | Step function; output 0 or 1 |
| **Hidden layer** | Middle layer; learns internal features |
| **MSE** | Mean Squared Error: E = (1/2)(d−y)²; loss function |
| **Supervised learning** | Training with labeled (X,Y) pairs |
| **Unsupervised learning** | Training on unlabeled data; finds patterns |
| **Reinforcement learning** | Agent learns via rewards and penalties |
| **Agent** | The learning/decision-making entity in RL |
| **Policy** | Strategy mapping states → actions |
| **Reward** | Positive feedback signal in RL |

### Bayesian Network

| Term | Definition |
|------|-----------|
| **Bayesian Network** | Probabilistic graphical model: DAG + CPTs |
| **DAG** | Directed Acyclic Graph — directed edges, no cycles |
| **CPT** | Conditional Probability Table: P(X\|Parents(X)) |
| **Prior probability** | P(X) for a root node with no parents |
| **Conditional independence** | X ⊥ Y \| Z — X and Y independent when Z is known |
| **Marginal independence** | X ⊥ Y — independent unconditionally |
| **Explaining away** | Observing Alarm makes B and E dependent |
| **Singly connected BN** | At most one undirected path between any two nodes |
| **Normalization α** | Ensures probabilities sum to 1 |
| **Marginalization** | Summing out: P(X) = Σᵧ P(X,Y) |
| **Joint distribution** | Probability of all variables taking specific values |

---

## 18. References

| Content | Source |
|---------|--------|
| Biological vs Artificial Neuron | Russell & Norvig, *AI: A Modern Approach*, Ch. 18 |
| Mathematical model of neuron | *Neural Networks — The Mathematical Model*, York University |
| ANN 3-layer architecture | Standard feed-forward network; R&N Ch. 18 |
| Sigmoid function | Haykin, *Neural Networks and Learning Machines*, 3rd Ed. |
| MSE loss function | R&N Ch. 18; standard ML reference |
| Supervised / Unsupervised / RL | GeeksforGeeks; Fiveable AI study guide |
| Compute Z solved examples | AI Question Bank — 6th Sem Q6(b), 4th Sem Q5(d) |
| BN definition, CPT concept | Slide 7, `06-bayesian-networks.pdf` |
| Cavity example | Slide 9, `06-bayesian-networks.pdf` |
| Burglary–Alarm problem | Slide 10, `06-bayesian-networks.pdf` |
| Burglary–Alarm DAG | Slide 11, `06-bayesian-networks.pdf` |
| Full CPT table | Slide 12, `06-bayesian-networks.pdf` |
| Independence rules | Slides 13–15, `06-bayesian-networks.pdf` |
| BN construction algorithm | Slide 23, `06-bayesian-networks.pdf` |
| Variable ordering example | Slides 24–29, `06-bayesian-networks.pdf` |
| Joint probability P(J∧M∧A∧¬B∧¬E) | Slides 18–21, `06-bayesian-networks.pdf` |
| Querying BN, marginalization | Slides 30–33, `06-bayesian-networks.pdf` |
| Singly connected BN | Slide 34, `06-bayesian-networks.pdf` |
| Chain rule formula | [Berkeley CS188 Textbook](https://inst.eecs.berkeley.edu/~cs188/textbook/bayes-nets/representation.html) |

---

*Prepared for AI exam preparation — RMSTU CSE, 4th/5th/6th/7th Semester.*
