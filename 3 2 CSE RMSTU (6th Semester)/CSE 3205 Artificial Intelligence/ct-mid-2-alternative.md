# Neural Networks & Bayesian Networks — Exam Q&A Notes
### AI Question Bank Coverage: 4th, 5th, 6th, 7th Semester (Mid & Final Exam)
> **Primary Reference:** *Artificial Intelligence: A Modern Approach* — Russell & Norvig  
> **Lecture Slides:** `06-bayesian-networks.pdf` (Jean Claude Latombe / Hwee Tou Ng)

---

## Table of Contents

### Part A — Neural Networks (Q&A)

- [Q1 — Define neuron. Describe the mathematical model of a neuron.](#q1--define-neuron-describe-the-mathematical-model-of-a-neuron)
  *(7th Sem Q5(a) | 7th Sem Q6(b) | 6th Sem Q6(a) | 5th Sem Q5(b) | 4th Sem Q5(c))*

- [Q2 — Discuss the classification approaches to pattern recognition.](#q2--discuss-the-classification-approaches-to-pattern-recognition)
  *(7th Sem Q5(b))*

- [Q3 — Discuss about various types of knowledge to build a neural network.](#q3--discuss-about-various-types-of-knowledge-to-build-a-neural-network)
  *(7th Sem Q5(c))*

- [Q4 — What do you mean by learning? Write short note about reinforcement learning.](#q4--what-do-you-mean-by-learning-write-short-note-about-reinforcement-learning)
  *(7th Sem Q5(d) | 5th Sem Q5(d))*

- [Q5 — What do you mean by learning? Describe reinforcement, supervised and unsupervised learning.](#q5--what-do-you-mean-by-learning-describe-reinforcement-supervised-and-unsupervised-learning)
  *(6th Sem Q6(c))*

- [Q6 — Distinguish between supervised learning and unsupervised learning.](#q6--distinguish-between-supervised-learning-and-unsupervised-learning)
  *(5th Sem Q6(b))*

- [Q7 — What is brain? It is faster than the fastest digital computer. Explain.](#q7--what-is-brain-it-is-faster-than-the-fastest-digital-computer-explain)
  *(5th Sem Q6(c))*

- [Q8 — Compute Z without a transfer function.](#q8--compute-z-without-a-transfer-function)
  *(6th Sem Q6(b)-i | 4th Sem Q5(d)-i | 7th Sem Q6(c)-i | 5th Sem Q5(c)-i)*

- [Q9 — Compare Z with a threshold function. If value ≤5 → 0, else → 1.](#q9--compare-z-with-a-threshold-function-if-value-5--0-else--1)
  *(4th Sem Q5(d)-ii | 6th Sem Q6(b)-ii)*

- [Q10 — Compute Z with sigmoid transfer function used at all neurons.](#q10--compute-z-with-sigmoid-transfer-function-used-at-all-neurons)
  *(4th Sem Q5(d)-iii | 6th Sem Q6(b)-iii)*

- [Q11 — Compute Z with the Mean Squared Error function E used at all neurons.](#q11--compute-z-with-the-mean-squared-error-function-e-used-at-all-neurons)
  *(7th Sem Q6(c)-ii | 5th Sem Q5(c)-ii)*

### Part B — Bayesian Networks (Q&A)

- [Q12 — Are Burglary and Earthquake independent if no evidence is observed? Justify.](#q12--are-burglary-and-earthquake-independent-if-no-evidence-is-observed-justify)
  *(5th Sem Q6(d)-i | 4th Sem Q6(d)-i)*

- [Q13 — Determine P(Alarm, no Burglary, no Earthquake, John and Mary call).](#q13--determine-palarm-no-burglary-no-earthquake-john-and-mary-call)
  *(5th Sem Q6(d)-ii | 4th Sem Q6(d)-ii)*

- [Q14 — Determine P(Alarm, Burglary, no Earthquake, John and Mary call).](#q14--determine-palarm-burglary-no-earthquake-john-and-mary-call)
  *(5th Sem Q6(d)-iii | 4th Sem Q6(d)-iii)*

### Appendix
- [Concept Reference Sheets](#concept-reference-sheets)
- [Key Terminology Glossary](#key-terminology-glossary)
- [All Exam Questions Index](#all-exam-questions-index)
- [References](#references)

---

# PART A — NEURAL NETWORKS

---

## Q1 — Define neuron. Describe the mathematical model of a neuron.
> *7th Sem Q5(a) | 7th Sem Q6(b) | 6th Sem Q6(a) | 5th Sem Q5(b) | 4th Sem Q5(c)*

---

### Define Neuron

A **neuron** is the fundamental structural and functional unit of both the biological nervous system and an Artificial Neural Network (ANN).

**Biological Neuron:**
A nerve cell in the human brain that receives electrical/chemical signals through **dendrites**, processes them in the **cell body (soma)**, and transmits the result through the **axon** to the next neuron. The human brain contains approximately **86 billion** neurons, each connected to thousands of others.

![Biological Neuron — Labeled Diagram (Wikipedia Commons)](https://upload.wikimedia.org/wikipedia/commons/thumb/b/bc/Neuron_Hand-tuned.svg/1024px-Neuron_Hand-tuned.svg.png)
*Fig 1: Labeled diagram of a biological neuron — dendrites receive signals, cell body processes them, axon transmits output. (Source: Wikipedia Commons, CC BY-SA)*

```
        Dendrites                    Axon Terminals
        (inputs)                     (outputs)
           │                              │
    ───────▼──────────────────────────────▼───────
    │  Dendrites ──► Cell Body (Soma) ──► Axon  │
    ──────────────────────────────────────────────
```

**Artificial Neuron:**
A mathematical model that mimics the biological neuron. It takes multiple **weighted inputs**, computes their **sum**, and passes the result through an **activation function** to produce an output.

**Biological → Artificial Mapping:**

| Biological Part | Function | Artificial Equivalent |
|-----------------|----------|-----------------------|
| Dendrites | Receive incoming signals | Inputs (x₁, x₂, ..., xₙ) |
| Synapse | Connection strength between neurons | Weights (w₁, w₂, ..., wₙ) |
| Cell Body (Soma) | Accumulates and processes signals | Summation function (Σ) |
| Axon | Transmits output to next neuron | Output signal (y) |
| Threshold | Decides whether neuron fires | Activation function φ(.) |

> *A negative weight reflects an inhibitory connection; a positive weight reflects an excitatory connection.*

**Biological vs Artificial — Key Differences:**

| Feature | Biological Neuron | Artificial Neuron |
|---------|-------------------|-------------------|
| Speed | ~200 Hz (slow electrochemical) | GHz (very fast electronic) |
| Learning | Synaptic plasticity | Weight adjustment (backpropagation) |
| Fault tolerance | Very high | Moderate |
| Parallelism | ~10¹⁴ connections | Simulated in software |
| Energy | ~20W (whole brain) | High (GPU-dependent) |

---

### Describe the Mathematical Model of a Neuron

The mathematical model of an artificial neuron has **two stages**:

**Diagram — Single Artificial Neuron:**

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

**Stage 1 — Weighted Summation (net input):**

Each input `xᵢ` is multiplied by weight `wᵢ`; the products are summed with a bias `b`:

```
net = Σᵢ (wᵢ × xᵢ) + b
    = w₁x₁ + w₂x₂ + ... + wₙxₙ + b
```

**Stage 2 — Activation Function:**

The net input passes through activation function φ to produce output y:

```
y = φ(net)
```

**Combined formula:**
```
y = φ( w₁x₁ + w₂x₂ + ... + wₙxₙ + b )
```

**Components:**

| Symbol | Name | Role |
|--------|------|------|
| x₁…xₙ | Inputs | Raw feature values |
| w₁…wₙ | Weights | Strength/importance of each connection |
| b | Bias | Shifts the activation threshold |
| Σ | Summation | Computes weighted sum of all inputs |
| φ(.) | Activation function | Produces final output (sigmoid, threshold, etc.) |
| y | Output | Neuron's response signal |

**Common Activation Functions:**

| Function | Formula | Output Range | Use Case |
|----------|---------|-------------|----------|
| Linear (none) | φ(net) = net | (−∞, +∞) | Raw sum, no transformation |
| Threshold (Step) | φ(net) = 1 if net ≥ θ, else 0 | {0, 1} | Binary classification |
| Sigmoid | φ(net) = 1 / (1 + e⁻ⁿᵉᵗ) | (0, 1) | Smooth probabilistic output |

**Multi-layer notation** (hidden layer Y → output Z):
```
Hidden neuron Yⱼ :   Yⱼ = φ( Σᵢ wᵢⱼ × xᵢ )
Output neuron Z  :   Z  = φ( Σⱼ vⱼ  × Yⱼ )
```

> *The mathematical model shows how weighted summation + non-linear activation can learn complex patterns — the foundation of all neural networks.*

---

## Q2 — Discuss the classification approaches to pattern recognition.
> *7th Sem Q5(b)*

---

### Concept: What is Pattern Recognition?

**Pattern recognition** is the ability of a system to identify regularities, structures, or categories in input data. It is one of the core applications of AI and neural networks.

*Examples:* recognizing handwritten digits, detecting faces, classifying emails as spam.

---

### Classification Approaches to Pattern Recognition

There are **three main approaches**:

```
              PATTERN RECOGNITION
                      │
       ┌──────────────┼──────────────┐
       ▼              ▼              ▼
  Statistical      Syntactic     Neural Network
  Approach         Approach        Approach
(Probability)  (Grammar/Rules)  (Learned data)
```

---

**① Statistical (Probabilistic) Approach**

Uses probability theory to classify patterns based on statistical properties of the data.

```
Given input X → Compute P(class | X) → Assign to highest-probability class
```

- Based on **Bayes' theorem**: `P(class | X) ∝ P(X | class) × P(class)`
- Assumes data follows a known statistical distribution (e.g., Gaussian)
- Works well when training data is large and distribution is known

| Feature | Detail |
|---------|--------|
| Basis | Probability & statistics |
| Key method | Bayes classifier, Gaussian Mixture Models |
| Strength | Handles uncertainty naturally |
| Weakness | Requires knowing the data distribution |

*Example:* A spam filter that computes the probability an email is spam based on word frequencies.

---

**② Syntactic (Structural) Approach**

Represents patterns as structured objects using **formal grammars and rules**.

```
Pattern = arrangement of primitives governed by a formal grammar
          → Classification by parsing the input against the grammar
```

- Patterns described using **primitive elements** + **rules** for combining them
- A grammar defines valid patterns; input classified by parsing
- Best for patterns with hierarchical or sequential structure

| Feature | Detail |
|---------|--------|
| Basis | Formal grammars, parsing rules |
| Key method | Context-free grammars, finite automata |
| Strength | Captures structural and hierarchical relationships |
| Weakness | Difficult to handle noise or distortion |

*Example:* Recognizing chemical molecular structures; classifying handwritten Chinese characters as sequences of strokes.

---

**③ Neural Network (Connectionist) Approach**

Uses artificial neural networks to **learn** a classification function directly from data.

```
Training data (X, label) → ANN learns weights → New input X → Predicted label
```

- No need to hand-craft rules or assume a probability distribution
- Network **automatically extracts features** during training
- Uses **backpropagation** to adjust weights and minimize error

| Feature | Detail |
|---------|--------|
| Basis | Weighted connections, learned from data |
| Key method | Multi-layer perceptron (MLP), CNN, RNN |
| Strength | Handles complex, high-dimensional patterns |
| Weakness | Requires large data; less interpretable ("black box") |

*Example:* A CNN classifying images as "cat" or "dog."

---

**Comparison Table:**

| Feature | Statistical | Syntactic | Neural Network |
|---------|------------|-----------|----------------|
| Basis | Probability | Grammar/Rules | Learned weights |
| Training needed | Yes (distribution) | No (rules defined) | Yes (labeled data) |
| Handles noise | Moderate | Poor | Very good |
| Interpretability | Moderate | High | Low |
| Best for | Numeric/tabular data | Structured/sequential | Images, speech, text |
| Example algorithm | Bayes classifier | Grammar parser | CNN, MLP |

> *Neural networks dominate modern pattern recognition because they handle noise, high dimensionality, and complex patterns without manual feature engineering.*

---

## Q3 — Discuss about various types of knowledge to build a neural network.
> *7th Sem Q5(c)*

---

### Concept: Types of Knowledge in Neural Networks

To build an effective neural network, four types of knowledge are used:

---

**① Prior Knowledge (Domain Knowledge)**

Knowledge about the problem domain that is built into the network before training.

- Determines network **architecture** (number of layers, neurons, connectivity)
- Example: For image recognition, knowing spatial locality → use Convolutional layers
- Can constrain the weight space so the network learns faster

*Source:* Human experts, textbooks, physics equations

---

**② Training Knowledge (Examples / Data)**

The network learns from labeled examples during the training process.

```
Training set: (input x₁, target y₁), (x₂, y₂), ..., (xₙ, yₙ)
                        ↓
           Backpropagation adjusts weights
                        ↓
          Network minimizes error E = (1/2)(d − y)²
```

- This is the primary source of knowledge in supervised learning
- More training data → better generalization

---

**③ Heuristic Knowledge (Rules of Thumb)**

Practical guidelines developed through experience with neural networks:

| Heuristic | Guideline |
|-----------|-----------|
| Network size | Start small; grow if needed |
| Learning rate | Use small values (e.g., 0.01) to avoid oscillation |
| Initialization | Initialize weights randomly near zero |
| Activation function | Use sigmoid for hidden layers; softmax for output |
| Stopping criterion | Stop when validation error stops decreasing |

---

**④ Structural Knowledge (Architecture Knowledge)**

Defines how neurons are connected — the topology of the network:

```
 INPUT LAYER     HIDDEN LAYER(S)     OUTPUT LAYER
 ───────────     ───────────────     ────────────
    x₁ ──────────► H₁ ───────────┐
    x₂ ──────────► H₂ ───────────┤──► Z (output)
    x₃ ──────────► H₃ ───────────┘
```

| Layer | Role |
|-------|------|
| Input Layer | Receives raw features; one neuron per input variable |
| Hidden Layer(s) | Learns internal representations; number is configurable |
| Output Layer | Produces final prediction; one neuron per output class |

**Types of neural network architectures:**
- **Feed-forward** — information flows only forward (no cycles)
- **Recurrent** — has feedback connections (for sequential data)
- **Convolutional** — uses local receptive fields (for images)

> *Combining all four types of knowledge enables a neural network to learn efficiently, generalize well, and solve complex real-world problems.*

---

## Q4 — What do you mean by learning? Write short note about reinforcement learning.
> *7th Sem Q5(d) | 5th Sem Q5(d)*

---

### What is Learning?

**Learning** in AI is the ability of a system to **improve its performance** on tasks through **experience**, without being explicitly reprogrammed for every situation.

Formally: A program is said to **learn** from experience E, with respect to task T and performance measure P, if its performance on T improves with experience E. *(Mitchell, 1997)*

```
Experience (data) → Learning Algorithm → Improved Performance
```

*Example:* An email spam filter that gets better at detecting spam the more emails it processes.

---

### Reinforcement Learning

**Reinforcement Learning (RL)** is a type of machine learning where an **agent** learns to make decisions by interacting with an **environment** and receiving **rewards or penalties**.

**Core Idea:**
```
        ┌──────────────────────────────────────┐
        │                                      │
        ▼                                      │
   ┌─────────┐   Action (a)   ┌─────────────┐  │
   │  Agent  │ ─────────────► │ Environment │  │
   └─────────┘                └─────────────┘  │
        ▲                           │           │
        │    State (s) + Reward (r) │           │
        └───────────────────────────┘           │
                                                │
        Agent updates policy ───────────────────┘
```

**Key Components:**

| Term | Meaning |
|------|---------|
| Agent | The learner/decision-maker |
| Environment | What the agent interacts with |
| State (s) | Current situation of the agent |
| Action (a) | What the agent does in a state |
| Reward (r) | Feedback — positive for good action, negative for bad |
| Policy (π) | Strategy that maps states → actions |

**How it works:**
1. Agent observes the current **state** of the environment
2. Agent takes an **action** based on its policy
3. Environment transitions to a new state and gives a **reward**
4. Agent updates its policy to maximize cumulative future reward

**Characteristics:**

| Feature | Detail |
|---------|--------|
| Data | No fixed dataset — learns from live interaction |
| Goal | Maximize total cumulative reward over time |
| Feedback | Delayed reward/penalty (not immediate) |
| Examples | Chess AI, robotics, self-driving cars, AlphaGo |

**Analogy:** Training a dog — give a treat for sitting on command, scold for bad behaviour. The dog learns to repeat actions that bring rewards.

> *Reinforcement learning is especially powerful for sequential decision-making tasks where the correct action is not known in advance but can be discovered through trial and error.*

---

## Q5 — What do you mean by learning? Describe reinforcement, supervised and unsupervised learning with examples.
> *6th Sem Q6(c)*

---

### What is Learning?

**Learning** in AI is the ability of a system to improve its performance on tasks through experience, without being explicitly reprogrammed.

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

### (a) Supervised Learning

The model is trained on **labeled input-output pairs** — the "teacher" provides the correct answers.

```
Training Data:  (X₁,Y₁), (X₂,Y₂), ..., (Xₙ,Yₙ)
                        ↓
               Model learns f: X → Y
                        ↓
          New input X_new → Predict Y_new
```

![Supervised Learning Diagram (Wikipedia Commons)](https://upload.wikimedia.org/wikipedia/commons/thumb/3/35/Supervised_learning_illustration.png/800px-Supervised_learning_illustration.png)
*Fig 2: Supervised learning — model trained on labeled input-output pairs (X, Y). (Source: Wikipedia Commons, CC BY-SA)*

| Feature | Detail |
|---------|--------|
| Data | Labeled pairs (input X, output Y) |
| Goal | Learn mapping input → output |
| Feedback | Direct — error between predicted and actual |
| Task types | Classification, Regression |
| Examples | Spam detection, image classification, house price prediction |

*Analogy:* Studying with a textbook that has an answer key — the teacher provides correct labels for every example.

---

### (b) Unsupervised Learning

The model finds **hidden patterns or structure** in **unlabeled** data — no correct output is given.

```
Unlabeled Data: X₁, X₂, X₃, ..., Xₙ
                        ↓
         Algorithm discovers structure
                        ↓
          Clusters / Patterns / Groups
```

![Unsupervised Learning — K-Means Clustering (Wikipedia Commons)](https://upload.wikimedia.org/wikipedia/commons/thumb/e/ea/K-means_convergence.gif/617px-K-means_convergence.gif)
*Fig 3: Unsupervised learning — K-Means clustering discovers groups in unlabeled data without any pre-defined labels. (Source: Wikipedia Commons, CC BY-SA)*

| Feature | Detail |
|---------|--------|
| Data | Unlabeled — no output labels provided |
| Goal | Find hidden patterns, clusters, or structure |
| Feedback | None — no ground truth |
| Task types | Clustering, Dimensionality reduction, Association |
| Examples | Customer segmentation, anomaly detection, PCA |

*Analogy:* Sorting unknown seashells into groups by shape — no guide, just observed similarity.

---

### (c) Reinforcement Learning

An **agent** learns by interacting with an **environment** and receiving **rewards** or **penalties** for its actions.

![Reinforcement Learning Agent-Environment Loop (Wikipedia Commons)](https://upload.wikimedia.org/wikipedia/commons/thumb/1/1b/Reinforcement_learning_diagram.svg/800px-Reinforcement_learning_diagram.svg.png)
*Fig 4: Reinforcement learning — agent takes actions in environment, receives state and reward, updates policy. (Source: Wikipedia Commons, CC BY-SA)*

```
   ┌─────────┐   Action a    ┌─────────────┐
   │  Agent  │ ────────────► │ Environment │
   └─────────┘               └─────────────┘
        ▲                          │
        │    State s + Reward r    │
        └──────────────────────────┘
```

| Feature | Detail |
|---------|--------|
| Data | No fixed dataset — learned from environment |
| Goal | Maximize cumulative reward |
| Feedback | Delayed reward/penalty |
| Examples | AlphaGo (chess/Go), robotics, self-driving cars |

*Analogy:* Training a dog with treats and scolding — the dog learns to maximise rewarded behaviour.

---

**Comparison of All Three:**

| Feature | Supervised | Unsupervised | Reinforcement |
|---------|-----------|--------------|---------------|
| Data type | Labeled (X, Y) | Unlabeled (X only) | No fixed dataset |
| Output | Predefined labels | Discovered structure | Cumulative reward |
| Feedback | Immediate error signal | None | Delayed reward/penalty |
| Task type | Classification, Regression | Clustering, Association | Sequential decisions |
| Example algorithms | Neural Net, SVM, Decision Tree | K-Means, PCA | Q-Learning, DQN |
| Real example | Email spam filter | Customer segmentation | Chess-playing AlphaGo |

---

## Q6 — Distinguish between supervised learning and unsupervised learning.
> *5th Sem Q6(b)*

---

### Concept

Both supervised and unsupervised learning are types of machine learning, but they differ fundamentally in the type of data they use and the way they learn.

---

### Supervised Learning

Trained on **labeled** data — each input has a known correct output provided by a "teacher."

```
Input X  ─────────────────────────────────► Model ──► Predicted Output Ŷ
                                                            │
                  Known correct label Y ────────────► Error (Ŷ − Y)
                                                            │
                                                   Adjust weights
```

*Example:* Training a model on photos labeled "cat" or "dog" → model learns to classify new photos.

---

### Unsupervised Learning

Trained on **unlabeled** data — no correct output is given; the model discovers structure on its own.

```
Input X₁, X₂, X₃ ... ──► Model discovers groups ──► Cluster A, Cluster B ...
                              (no labels provided)
```

*Example:* Grouping customers into segments based on purchase history — no pre-defined categories given.

---

### Comparison Table

| Feature | Supervised Learning | Unsupervised Learning |
|---------|--------------------|-----------------------|
| Input data | Labeled (X, Y pairs) | Unlabeled (X only) |
| Goal | Learn X → Y mapping | Discover hidden structure |
| Feedback | Direct error signal | None |
| Human involvement | High (labeling required) | Low |
| Task type | Classification, Regression | Clustering, Association, Dimensionality reduction |
| Algorithms | Neural Net, SVM, Decision Tree, KNN | K-Means, DBSCAN, PCA, Autoencoder |
| Real example | Spam detection, image classification | Customer segmentation, anomaly detection |
| Evaluation | Measurable accuracy | Harder to evaluate objectively |

> *Supervised learning is used when you have labeled examples; unsupervised learning is used when you want the data to reveal its own structure.*

---

## Q7 — What is brain? It is faster than the fastest digital computer. Explain.
> *5th Sem Q6(c)*

---

### Concept: The Human Brain

The **human brain** is the biological neural processing organ of the human body. It is the most complex known object in the universe, containing approximately **86 billion neurons**, each connected to thousands of others through **synapses** — forming a network of roughly **100 trillion connections**.

**Basic structure:**
```
        Biological Neuron
        ─────────────────
Dendrites (inputs) → Cell Body (processing) → Axon → Synapse → Next Neuron
```

---

### Is the Brain Faster Than the Fastest Digital Computer?

In certain respects, **yes** — and the reasons are important to understand:

**① Massive Parallelism**

The brain processes information in **parallel across billions of neurons simultaneously**. A digital computer, even with multiple cores, processes mostly sequentially.

```
Brain:     Neuron₁ ─── process
           Neuron₂ ─── process    ← All happening at the SAME time
           Neuron₃ ─── process
           ...86 billion...

Computer:  Core₁ → task₁ → task₂ → task₃ ...  (mostly sequential)
```

*Example:* When you catch a ball, your brain is simultaneously processing vision, balance, muscle control, and prediction — all in real time.

**② Energy Efficiency**

The entire human brain runs on approximately **20 watts** — less than a dim light bulb. A supercomputer performing equivalent tasks would require **megawatts** of power.

| System | Power Consumption |
|--------|------------------|
| Human brain | ~20 Watts |
| High-end GPU | ~300–500 Watts |
| Supercomputer (equivalent tasks) | Megawatts |

**③ Pattern Recognition Speed**

The brain can recognize a familiar face in **under 100 milliseconds** — a task that still requires significant computation in digital systems.

**④ Fault Tolerance and Adaptability**

Even if many neurons die, the brain adapts and compensates — digital computers fail if a single critical component breaks.

---

**Where Digital Computers Are Faster:**

| Task | Winner |
|------|--------|
| Arithmetic calculations (e.g., multiplying 10-digit numbers) | Computer |
| Data storage and retrieval (exact recall) | Computer |
| Pattern recognition (faces, voices) | Brain |
| Multisensory real-time processing | Brain |
| Energy efficiency | Brain |
| Creativity and generalization | Brain |

**Conclusion:**

The brain is not faster in raw arithmetic speed, but it is **architecturally superior** for perception, pattern recognition, and real-world intelligent tasks — achieved through **massive parallelism**, **energy efficiency**, and **adaptive learning**. This is exactly why neural networks were designed to **mimic the brain's architecture** rather than the sequential logic of a standard computer.

> *The brain's power comes not from clock speed but from billions of simple units working in parallel — the same principle behind artificial neural networks.*

---

## Q8 — Compute Z without a transfer function.
> *6th Sem Q6(b)-i | 4th Sem Q5(d)-i | 7th Sem Q6(c)-i | 5th Sem Q5(c)-i*

---

### Concept: Z Without Transfer Function

"Without a transfer function" means applying the **linear/identity activation**: the output of each neuron is simply its **raw weighted sum** — no sigmoid, no threshold, no transformation.

```
φ(net) = net    (output = raw sum, unchanged)
```

The computation flows layer by layer:
1. Compute each hidden neuron's weighted sum
2. Use those values directly (no activation) to compute Z

---

### Problem A — 6th Sem Q6(b)-i / 4th Sem Q5(d)-i

**Given:**
```
X₁ = 17,  X₂ = 7,  X₃ = 12
W₁ = 0.6  (X₁ → Y₁),  W₂ = 0.3  (X₂ → Y₁),  W₃ = 0.1  (X₃ → Y₂)
v₁ = 0.60 (Y₁ → Z),   v₂ = 0.45 (Y₂ → Z)
```

**Network Diagram:**
```
X₁(17) ──[0.6]──┐
                  ├──► Y₁ ──[0.60]──┐
X₂(7)  ──[0.3]──┘                   ├──► Z
                                      │
X₃(12) ──[0.1]────────► Y₂ ──[0.45]─┘
```

**Step 1 — Compute Y₁:**
```
Y₁ = W₁×X₁ + W₂×X₂
   = (0.6 × 17) + (0.3 × 7)
   = 10.2 + 2.1
   = 12.3
```

**Step 2 — Compute Y₂:**
```
Y₂ = W₃ × X₃
   = 0.1 × 12
   = 1.2
```

**Step 3 — Compute Z:**
```
Z = v₁×Y₁ + v₂×Y₂
  = (0.60 × 12.3) + (0.45 × 1.2)
  = 7.38 + 0.54
  = 7.92
```

> **✅ Answer: Z = 7.92**

---

### Problem B — 7th Sem Q6(c)-i / 5th Sem Q5(c)-i (x=1, y=1)

**Given:** x = 1, y = 1. Weights from exam diagram.

**General procedure:**
```
Step 1: H = w₁×x + w₂×y         (read w₁, w₂ from diagram)
Step 2: Z = v × H                 (read v from diagram)
Result: Z = raw weighted sum (no activation applied)
```

*Apply the same steps as Problem A using the specific weights shown in your exam paper's diagram.*

---

## Q9 — Compare Z with a threshold function. If value ≤5 → 0, else → 1.
> *4th Sem Q5(d)-ii | 6th Sem Q6(b)-ii*

---

### Concept: Threshold (Step) Function

The **threshold function** is a binary activation that outputs 0 or 1 based on whether the neuron's weighted sum crosses a threshold θ.

```
φ(net) = 0    if  net ≤ θ
φ(net) = 1    if  net > θ
```

For this exam question, **θ = 5**:
```
φ(net) = 0    if  net ≤ 5
φ(net) = 1    if  net > 5
```

The threshold is applied **at every neuron** — hidden neurons first, then the output neuron.

![Heaviside Step Function Graph (Wikipedia Commons)](https://upload.wikimedia.org/wikipedia/commons/thumb/d/d9/Dirac_distribution_CDF.svg/800px-Dirac_distribution_CDF.svg.png)
*Fig 5: Threshold (Step/Heaviside) activation function — output is 0 below threshold θ, jumps to 1 above it. (Source: Wikipedia Commons, CC BY-SA)*

---

### Solution (Same values as Q8 — X₁=17, X₂=7, X₃=12)

**Raw values from Q8:**
```
Y₁_raw = 12.3
Y₂_raw = 1.2
```

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

**Step 3 — Compute Z_raw using threshold outputs:**
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

**Summary Table:**

| Neuron | Raw Value | Condition | Threshold Output |
|--------|-----------|-----------|-----------------|
| Y₁ | 12.3 | 12.3 > 5 | **1** |
| Y₂ | 1.2 | 1.2 ≤ 5 | **0** |
| Z | 0.60 | 0.60 ≤ 5 | **0** |

> **✅ Answer: Z = 0**

---

## Q10 — Compute Z with sigmoid transfer function used at all neurons.
> *4th Sem Q5(d)-iii | 6th Sem Q6(b)-iii*

---

### Concept: Sigmoid Function

The **sigmoid** (logistic) function maps any real number to a smooth output between 0 and 1:

```
φ(net) = 1 / (1 + e^(−net))    Range: (0, 1)
```

![Sigmoid (Logistic) Function Graph (Wikipedia Commons)](https://upload.wikimedia.org/wikipedia/commons/thumb/8/88/Logistic-curve.svg/800px-Logistic-curve.svg.png)
*Fig 6: Sigmoid (logistic) function φ(x) = 1/(1+e⁻ˣ) — smooth S-curve mapping any input to (0,1). (Source: Wikipedia Commons, CC BY-SA)*

Properties:
- Output is always between 0 and 1 — interpretable as probability
- Smooth and differentiable — suitable for backpropagation
- Applied **at every neuron** — hidden neurons first, then output

---

### Solution (Same values as Q8 — X₁=17, X₂=7, X₃=12)

**Raw values from Q8:**
```
Y₁_raw = 12.3
Y₂_raw = 1.2
```

**Step 1 — Sigmoid on Y₁:**
```
φ(Y₁) = 1 / (1 + e^(−12.3))
       = 1 / (1 + 0.0000045)
       ≈ 0.9999955
       ≈ 1.000
```
*(e^−12.3 is extremely small → sigmoid ≈ 1)*

**Step 2 — Sigmoid on Y₂:**
```
φ(Y₂) = 1 / (1 + e^(−1.2))
       = 1 / (1 + 0.3012)
       = 1 / 1.3012
       ≈ 0.7685
```

**Step 3 — Compute Z_raw using sigmoid outputs:**
```
Z_raw = v₁ × φ(Y₁) + v₂ × φ(Y₂)
      = (0.60 × 1.000) + (0.45 × 0.7685)
      = 0.600 + 0.3458
      = 0.9458
```

**Step 4 — Sigmoid on Z:**
```
φ(Z) = 1 / (1 + e^(−0.9458))
     = 1 / (1 + 0.3885)
     = 1 / 1.3885
     ≈ 0.720
```

**Summary Table:**

| Neuron | Raw Value | Sigmoid Output |
|--------|-----------|----------------|
| Y₁ | 12.3 | ≈ 1.000 |
| Y₂ | 1.2 | ≈ 0.7685 |
| Z_raw | 0.9458 | — |
| Z_final | — | ≈ **0.720** |

> **✅ Answer: Z ≈ 0.720**

---

## Q11 — Compute Z with the Mean Squared Error function E used at all neurons.
> *7th Sem Q6(c)-ii | 5th Sem Q5(c)-ii*

---

### Concept: Mean Squared Error (MSE)

**MSE** is a **loss/error function** — it measures how far the network's output is from the desired output. It is NOT an activation function; it measures prediction error.

```
E = (1/2) × (d − y)²          [single output, simplified]
E = (1/n) × Σᵢ (dᵢ − yᵢ)²    [general form, n outputs]
```

Where:
- `d` = desired (target) output
- `y` = actual network output
- The `(1/2)` factor is a convenience that cancels when differentiating (used in backprop)

![Mean Squared Error Loss Function (Wikipedia Commons)](https://upload.wikimedia.org/wikipedia/commons/thumb/5/58/Cost_functions.svg/800px-Cost_functions.svg.png)
*Fig 7: Mean Squared Error (MSE) loss — measures distance between predicted output y and desired output d; E=(1/2)(d−y)². (Source: Wikipedia Commons, CC BY-SA)*

**"Compute Z with MSE at all neurons"** means:
1. First compute raw Z (no activation function — same as Q8)
2. Then compute E using the MSE formula with the given desired output d

---

### Solution

**Step 1 — Compute Z (without transfer function):**

*Use the same calculation as Q8 with the weights given in your exam diagram (x=1, y=1 for 7th/5th sem, or X₁=17, X₂=7, X₃=12 for 6th/4th sem).*

For the x=1, y=1 case:
```
H = w₁×1 + w₂×1   (read w₁, w₂ from diagram)
Z = v × H           (read v from diagram)
```

**Step 2 — Apply MSE Formula:**
```
E = (1/2) × (d − Z)²
```

Where `d` = the desired/target output given in the exam diagram.

**Step 3 — Report both Z and E.**

> **✅ Answer format:**
> - Z = [raw computed value]
> - E = (1/2) × (d − Z)² = [computed error]

> *If no desired output `d` is given in your exam diagram, compute Z from Step 1 and write the MSE formula stating that E = (1/2)(d − Z)².*

---

# PART B — BAYESIAN NETWORKS

---

### Background Concept: What is a Bayesian Network?

A **Bayesian Network (BN)** is a probabilistic graphical model that represents variables and their conditional dependencies using a **Directed Acyclic Graph (DAG)**.

> *"A simple, graphical notation for conditional independence assertions and hence for compact specification of full joint distributions."*  
> — Slide 7, `06-bayesian-networks.pdf`

**Why use BNs?**
- A belief state with n propositions needs 2ⁿ entries in a full joint table — expensive
- BNs exploit **conditional independence** to store far fewer numbers
- Example: Burglary–Alarm uses **10 numbers** instead of **31** (full joint for 5 variables)

**Structure:**

| Component | Description |
|-----------|-------------|
| Node | One per random variable |
| Directed Edge | "X directly influences Y" — causal relationship |
| CPT | Conditional Probability Table: P(X \| Parents(X)) |
| Root node | No parents → stores prior probability P(X) |
| Child node | Has parents → stores P(X \| Parents) |

> **Key rule:** A node with **k parents** has a CPT with **2ᵏ rows**.

---

### The Burglary–Alarm Network (used in Q12, Q13, Q14)

**Problem:** *"I'm at work; neighbor John calls to say my alarm is ringing. Sometimes it's set off by minor earthquakes. Is there a burglar?"*

**Variables:**

| Variable | Abbr. | Meaning |
|----------|-------|---------|
| Burglary | B | A burglar breaks in |
| Earthquake | E | Minor earthquake occurs |
| Alarm | A | Alarm goes off |
| JohnCalls | J | John calls the owner |
| MaryCalls | M | Mary calls the owner |

**Network DAG:**

![Bayesian Network DAG Example (Wikipedia Commons)](https://upload.wikimedia.org/wikipedia/commons/thumb/0/0e/SimpleBayesNet.svg/800px-SimpleBayesNet.svg.png)
*Fig 8: Bayesian Network — Directed Acyclic Graph (DAG) where nodes are variables, edges represent causal influence, and each node has a Conditional Probability Table (CPT). (Source: Wikipedia Commons, CC BY-SA)*

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
                 │  P(A|B, E)  │
                 └──────┬──────┘
                        │
           ┌────────────┴────────────┐
           ▼                         ▼
    ┌─────────────┐           ┌─────────────┐
    │  JohnCalls  │           │  MaryCalls  │
    │   P(J|A)    │           │   P(M|A)    │
    └─────────────┘           └─────────────┘
```

**All CPT Values:**

Prior probabilities:
```
P(B)  = 0.001       P(¬B) = 0.999
P(E)  = 0.002       P(¬E) = 0.998
```

P(Alarm | Burglary, Earthquake):

| B | E | P(A \| B,E) | P(¬A \| B,E) |
|---|---|-------------|--------------|
| T | T | **0.95** | 0.05 |
| T | F | **0.94** | 0.06 |
| F | T | **0.29** | 0.71 |
| F | F | **0.001** | 0.999 |

P(JohnCalls | Alarm):

| A | P(J \| A) | P(¬J \| A) |
|---|-----------|------------|
| T | **0.90** | 0.10 |
| F | **0.05** | 0.95 |

P(MaryCalls | Alarm):

| A | P(M \| A) | P(¬M \| A) |
|---|-----------|------------|
| T | **0.70** | 0.30 |
| F | **0.01** | 0.99 |

**General joint probability formula:**
```
P(X₁, X₂, ..., Xₙ) = Π P(Xᵢ | Parents(Xᵢ))
```

---

## Q12 — Are Burglary and Earthquake independent if no evidence is observed? Justify.
> *5th Sem Q6(d)-i | 4th Sem Q6(d)-i*

---

### Concept: Independence in Bayesian Networks

**Marginal independence**: Two variables X and Y are **independent** if:
```
P(X, Y) = P(X) × P(Y)
```

This means knowing X gives no information about Y (and vice versa).

In a Bayesian Network, the **structure of the DAG** directly encodes independence. The core rule is:

> *"A node is independent of its non-descendants given its parents."*

**Two nodes are marginally independent if there is no undirected path connecting them (ignoring arrow directions) — or more precisely, if all paths are "blocked."**

---

### 5th Sem Q6(d)-i Answer:
**Q: If no evidence is observed, are Burglary and Earthquake independent? Justify by calculation.**

**Answer: YES, they are marginally independent.**

**Justification — Structural:**
- In the DAG, Burglary (B) and Earthquake (E) are both **root nodes** (no parents)
- There is **no directed path** from B to E or from E to B
- They share a common **child** (Alarm), but with no evidence observed, this does not create dependence

**Justification — Mathematical:**

Definition of independence: P(B ∧ E) = P(B) × P(E)

```
Left side:   P(B ∧ E) = P(B) × P(E)    [because they are root nodes — independent by structure]
                       = 0.001 × 0.002
                       = 0.000002

Right side:  P(B) × P(E) = 0.001 × 0.002 = 0.000002
```

Since **P(B ∧ E) = P(B) × P(E) = 0.000002**, the independence condition is satisfied. ✅

> **Important note:** Once **Alarm is observed**, B and E become **dependent** — this is the **"explaining away"** effect. If the alarm rang and there was no earthquake, a burglary is more likely. Observing a common effect makes its causes correlated.

---

### 4th Sem Q6(d)-i Answer:
**Q: "If no evidence is observed, no calculation is needed. Probabilities of independence are high." Evaluate this statement.**

This statement is **partially correct but oversimplified**:

- **Correct part:** B and E are indeed independent when no evidence is observed — structural independence means no calculation is strictly required to confirm it (the DAG topology directly encodes it)
- **Incorrect part:** Independence is not about probabilities being "high" — it is a structural/mathematical property. Even low-probability events can be independent. The statement confuses the concept of independence with the magnitude of probabilities.

**Correct answer:** B and E are structurally independent because they are both root nodes with no connecting path in the DAG. The calculation P(B,E) = P(B)×P(E) = 0.000002 confirms this formally.

---

## Q13 — Determine P(Alarm, no Burglary, no Earthquake, John and Mary call).
> *5th Sem Q6(d)-ii | 4th Sem Q6(d)-ii*

---

### Concept: Joint Probability Using BN Chain Rule

The joint probability of any combination of variables in a BN is computed by multiplying the relevant CPT entries:

```
P(X₁, X₂, ..., Xₙ) = Π P(Xᵢ | Parents(Xᵢ))
```

The DAG structure tells us which variables are parents of which — so we know exactly which CPT row to look up for each variable.

---

### Solution: P(J ∧ M ∧ A ∧ ¬B ∧ ¬E)

*Alarm sounded (A=T), no Burglary (B=F), no Earthquake (E=F), John calls (J=T), Mary calls (M=T)*

**Step 1 — Write the expansion using the BN chain rule:**
```
P(J ∧ M ∧ A ∧ ¬B ∧ ¬E)
= P(J|A) × P(M|A) × P(A|¬B,¬E) × P(¬B) × P(¬E)
```

**Why this expansion?** From the DAG:
- J depends only on A → P(J | A, B, E) = P(J|A) ✅
- M depends only on A → P(M | A, B, E) = P(M|A) ✅
- A depends on B and E → P(A | B, E) — look up CPT row B=F, E=F ✅
- B and E are root nodes → P(¬B) and P(¬E) are priors ✅

**Step 2 — Look up CPT values:**
```
P(J|A=T)      = 0.90
P(M|A=T)      = 0.70
P(A=T|B=F,E=F) = 0.001
P(¬B)          = 0.999
P(¬E)          = 0.998
```

**Step 3 — Multiply:**
```
= 0.90 × 0.70 × 0.001 × 0.999 × 0.998

0.90 × 0.70        = 0.6300
0.6300 × 0.001     = 0.000630
0.000630 × 0.999   = 0.000629
0.000629 × 0.998   ≈ 0.000628
```

> **✅ Answer: P(J ∧ M ∧ A ∧ ¬B ∧ ¬E) ≈ 0.00062**

*(Slides 18–21, `06-bayesian-networks.pdf`)*

---

## Q14 — Determine P(Alarm, Burglary, no Earthquake, John and Mary call).
> *5th Sem Q6(d)-iii | 4th Sem Q6(d)-iii*

---

### Concept

Same approach as Q13, but now Burglary **occurred** (B=T). This changes which row of the Alarm CPT we look up: **P(A=T | B=T, E=F) = 0.94** instead of 0.001.

---

### Solution: P(J ∧ M ∧ A ∧ B ∧ ¬E)

*Alarm sounded (A=T), Burglary occurred (B=T), no Earthquake (E=F), John calls (J=T), Mary calls (M=T)*

**Step 1 — Expand using BN chain rule:**
```
P(J ∧ M ∧ A ∧ B ∧ ¬E)
= P(J|A) × P(M|A) × P(A|B=T, E=F) × P(B) × P(¬E)
```

**Step 2 — Look up CPT values:**
```
P(J|A=T)         = 0.90
P(M|A=T)         = 0.70
P(A=T|B=T, E=F)  = 0.94       ← different from Q13!
P(B)              = 0.001
P(¬E)             = 0.998
```

**Step 3 — Multiply:**
```
= 0.90 × 0.70 × 0.94 × 0.001 × 0.998

0.90 × 0.70        = 0.6300
0.6300 × 0.94      = 0.5922
0.5922 × 0.001     = 0.0005922
0.0005922 × 0.998  ≈ 0.000591
```

> **✅ Answer: P(J ∧ M ∧ A ∧ B ∧ ¬E) ≈ 0.000591**

---

**Comparison of Q13 vs Q14:**

| Scenario | Key difference | Answer |
|----------|---------------|--------|
| Q13: ¬B (no burglary) | P(A\|¬B,¬E) = 0.001 (very unlikely alarm without burglary) | ≈ 0.00062 |
| Q14: B (burglary occurred) | P(A\|B,¬E) = 0.94 (very likely alarm during burglary) | ≈ 0.000591 |

> *Interestingly, Q13's answer is slightly higher than Q14's — because although a burglary makes the alarm far more likely (0.94 vs 0.001), a burglary itself is also very unlikely (P(B)=0.001 vs P(¬B)=0.999). The prior probability of no burglary being so high compensates.*

---

# APPENDIX

---

## Concept Reference Sheets

### Neural Network Quick-Reference

| Formula | Meaning |
|---------|---------|
| `net = Σ(wᵢ × xᵢ) + b` | Weighted input sum at a neuron |
| `y = φ(net)` | Output after activation function |
| `Sigmoid: φ(x) = 1/(1 + e⁻ˣ)` | Smooth output in (0,1) |
| `Threshold: φ(x) = 1 if x>θ, else 0` | Binary step output |
| `MSE: E = (1/2)(d − y)²` | Loss/error function |
| `Y₁ = W₁X₁ + W₂X₂` | Hidden neuron (no activation) |
| `Z = v₁Y₁ + v₂Y₂` | Output neuron (no activation) |
| `Z_sigmoid = 1/(1 + e^−Z_raw)` | Z after sigmoid |

![Artificial Neural Network Architecture — Multi-Layer Perceptron (Wikipedia Commons)](https://upload.wikimedia.org/wikipedia/commons/thumb/4/46/Colored_neural_network.svg/800px-Colored_neural_network.svg.png)
*Fig 9: ANN feed-forward architecture — input layer (blue), hidden layer (green), output layer (orange). Each neuron computes weighted sum then applies activation function. (Source: Wikipedia Commons, CC BY-SA)*

### Bayesian Network Quick-Reference

| Formula | Description |
|---------|-------------|
| `P(X₁,...,Xₙ) = Πᵢ P(Xᵢ\|Parents(Xᵢ))` | Chain rule for BN |
| `P(C\|t) = α P(t\|C) P(C)` | Bayes' rule for querying |
| `CPT rows for k parents = 2ᵏ` | CPT size |
| `P(J∧M∧A∧¬B∧¬E) ≈ 0.00062` | Key exam answer (Q13) |
| `P(J∧M∧A∧B∧¬E) ≈ 0.000591` | Key exam answer (Q14) |
| `P(B,E) = P(B)×P(E) = 0.000002` | Independence proof (Q12) |

---

## All Exam Questions Index

### Neural Network Questions

| Sem | Q No. | Question | Answered In |
|-----|-------|---------|-------------|
| **7th** | Q5(a) | Define neuron. Describe the mathematical model of a neuron. **[4]** | Q1 |
| **7th** | Q5(b) | Discuss the classification approaches to pattern recognition. **[4]** | Q2 |
| **7th** | Q5(c) | Discuss about various types of knowledge to build a neural network. **[3]** | Q3 |
| **7th** | Q5(d) | What do you mean by learning? Write short note about reinforcement learning. **[4]** | Q4 |
| **7th** | Q6(b) | Define neuron. Describe the mathematical model of artificial neural network. | Q1 |
| **7th** | Q6(c)-i | Compute Z without a transfer function. (x=1, y=1) | Q8 |
| **7th** | Q6(c)-ii | Compute Z with the MSE function E used at all neurons. | Q11 |
| **6th** | Q6(a) | What do you mean by neuron of human brain? Describe the mathematical model. | Q1 |
| **6th** | Q6(b)-i | Compute Z without a transfer function. (X1=17, X2=7, X3=12...) | Q8 |
| **6th** | Q6(b)-ii | Compare Z with threshold function. If value ≤5 → 0, else → 1. | Q9 |
| **6th** | Q6(b)-iii | Compute Z with sigmoid transfer function used at all neurons. | Q10 |
| **6th** | Q6(c) | What do you mean by learning? Describe RL, supervised, unsupervised. **[5]** | Q5 |
| **5th** | Q5(b) | Define neuron. Describe the mathematical model of a neuron. **[4]** | Q1 |
| **5th** | Q5(c)-i | Compute Z without a transfer function. (x=1, y=1) | Q8 |
| **5th** | Q5(c)-ii | Compute Z with the MSE function E used at all neurons. | Q11 |
| **5th** | Q5(d) | What do you mean by learning? Write short note about reinforcement learning. **[3]** | Q4 |
| **5th** | Q6(b) | Distinguish between supervised and unsupervised learning. | Q6 |
| **5th** | Q6(c) | What is brain? It is faster than the fastest digital computer. Explain. | Q7 |
| **4th** | Q5(c) | Define neuron. Describe the mathematical model of a neuron. | Q1 |
| **4th** | Q5(d)-i | Compute Z without a transfer function. (X1=17, X2=7, X3=12...) | Q8 |
| **4th** | Q5(d)-ii | Compare Z with threshold function. If ≤5 → 0, else → 1. | Q9 |
| **4th** | Q5(d)-iii | Compute Z with the sigmoid transfer function used at all neurons. | Q10 |

### Bayesian Network Questions

| Sem | Q No. | Question | Answered In |
|-----|-------|---------|-------------|
| **5th** | Q6(d)-i | Are Burglary and Earthquake independent? Justify by calculation. | Q12 |
| **5th** | Q6(d)-ii | P(Alarm, no Burglary, no Earthquake, John and Mary call). | Q13 |
| **5th** | Q6(d)-iii | P(Alarm, Burglary, no Earthquake, John and Mary call). | Q14 |
| **4th** | Q6(d)-i | Evaluate: "No evidence → no calculation needed; independence is high." | Q12 |
| **4th** | Q6(d)-ii | P(Alarm, no Burglary, no Earthquake, John and Mary call). | Q13 |
| **4th** | Q6(d)-iii | P(Alarm, Burglary, no Earthquake, John and Mary call). | Q14 |

### Answer Summary

| Question | Answer |
|----------|--------|
| Z without transfer function (X1=17...) | **Z = 7.92** |
| Z with threshold (θ=5) | **Z = 0** |
| Z with sigmoid | **Z ≈ 0.720** |
| P(B,E) — independence check | **0.000002 = P(B)×P(E) → Independent ✅** |
| P(J∧M∧A∧¬B∧¬E) | **≈ 0.00062** |
| P(J∧M∧A∧B∧¬E) | **≈ 0.000591** |

---

## Key Terminology Glossary

### Neural Network

| Term | Definition |
|------|-----------|
| **Neuron (Artificial)** | Basic computing unit; computes weighted sum then applies activation |
| **Weight (w)** | Strength of connection between neurons |
| **Bias (b)** | Extra input shifting the activation threshold |
| **Net input** | net = Σ(wᵢxᵢ) + b |
| **Activation function** | Non-linear function φ applied to net input |
| **Sigmoid** | φ(x) = 1/(1+e⁻ˣ); output in (0,1) |
| **Threshold function** | Step function; output 0 or 1 based on threshold |
| **Hidden layer** | Middle layer; learns internal features |
| **MSE** | Mean Squared Error: E = (1/2)(d−y)²; loss function |
| **Supervised learning** | Training with labeled (X,Y) pairs |
| **Unsupervised learning** | Training on unlabeled data; finds patterns |
| **Reinforcement learning** | Agent learns via rewards and penalties |
| **Agent** | The learning/decision-making entity in RL |
| **Policy** | Strategy mapping states → actions |
| **Reward** | Positive feedback signal in RL |
| **Backpropagation** | Algorithm for computing weight gradients |
| **Pattern recognition** | Identifying regularities/categories in input data |

### Bayesian Network

| Term | Definition |
|------|-----------|
| **Bayesian Network** | Probabilistic graphical model: DAG + CPTs |
| **DAG** | Directed Acyclic Graph — directed edges, no cycles |
| **CPT** | Conditional Probability Table: P(X\|Parents(X)) |
| **Prior probability** | P(X) for a root node with no parents |
| **Conditional independence** | X ⊥ Y \| Z — X and Y independent when Z is known |
| **Marginal independence** | X ⊥ Y — independent unconditionally |
| **Explaining away** | Observing a common effect makes its causes correlated |
| **Singly connected BN** | At most one undirected path between any two nodes |
| **Normalization α** | Ensures probabilities sum to 1 |
| **Marginalization** | Summing out: P(X) = Σᵧ P(X,Y) |
| **Joint distribution** | Probability of all variables taking specific values |

---

## References

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
| Burglary–Alarm problem | Slide 10, `06-bayesian-networks.pdf` |
| Full CPT table | Slide 12, `06-bayesian-networks.pdf` |
| Independence rules | Slides 13–15, `06-bayesian-networks.pdf` |
| Joint probability P(J∧M∧A∧¬B∧¬E) | Slides 18–21, `06-bayesian-networks.pdf` |
| Chain rule formula | [Berkeley CS188 Textbook](https://inst.eecs.berkeley.edu/~cs188/textbook/bayes-nets/representation.html) |

---

*Prepared for AI exam preparation — RMSTU CSE, 4th/5th/6th/7th Semester.*
