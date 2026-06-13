# Information Gathering Tools
### Course: System Analysis and Design
### Topic: Information Gathering Tools — Pros and Cons

---

> **Submitted by:** MD. Kamrul Hassan (Tanvir)
> **Department:** Computer Science and Engineering
> **Institution:** Rangamati Science and Technology University (RMSTU)
> **Supervised by:** Dr. Mithun Dutta, Assistant Professor, CSE Department
> **Primary Reference:** Awad, E. M. — *Systems Analysis and Design*, Chapter 5

---

## Table of Contents

1. [Introduction](#1-introduction)
2. [What Kinds of Information Do We Need?](#2-what-kinds-of-information-do-we-need)
3. [Sources of Information](#3-sources-of-information)
4. [Tool 1 — Review of Literature, Procedures, and Forms](#4-tool-1--review-of-literature-procedures-and-forms)
5. [Tool 2 — On-Site Observation](#5-tool-2--on-site-observation)
6. [Tool 3 — Interviews](#6-tool-3--interviews)
7. [Tool 4 — Questionnaires](#7-tool-4--questionnaires)
8. [Structured vs. Unstructured Approaches](#8-structured-vs-unstructured-approaches)
9. [Reliability and Validity of Information](#9-reliability-and-validity-of-information)
10. [Comparative Summary](#10-comparative-summary)
11. [Conclusion](#11-conclusion)
12. [References](#12-references)

---

## 1. Introduction

Before a system can be designed, a systems analyst must develop a thorough understanding of the existing system, user needs, decision-making processes, and work flows. Awad (Ch. 5) describes this process as progressing through three stages:

1. **Familiarity with the present system** — through documentation, interviews, and observation.
2. **Defining decision-making structures** — identifying decision points and how decisions are made.
3. **Defining information requirements** — gathering, analyzing, and documenting user needs; identifying gaps between the current information system and what the system actually requires.

The tools used to accomplish this are not one-size-fits-all. As Awad states: *"No two projects are ever the same. This means that the analyst must decide on the information gathering tool and how it must be used."* The key rule is that **information must be acquired accurately, methodically, under the right conditions, and with minimum interruption to user personnel.**

Awad identifies four core information-gathering tools:
- Review of Literature, Procedures, and Forms
- On-Site Observation
- Interviews
- Questionnaires

Each is examined in detail below with pros, cons, and modern enrichment.

---

## 2. What Kinds of Information Do We Need?

Awad organizes the information needed for systems analysis into three categories:

### Information about the Firm
Policies, goals, objectives, and organizational structure. This explains the environment that promotes or hinders the introduction of computer-based systems. Sources include employee manuals, orientation pamphlets, annual reports, and the organization chart.

> The organization chart reveals management direction. For example, a family-owned firm with a rigid, centralized structure signals that the analyst faces a challenge in selling the project before final approval.

### Information about User Staff
Job functions, information requirements, and interpersonal relationships. Key employees who have been in the user area for years are especially valuable — they hold historical and sometimes sensitive information available from no other source (Awad calls these individuals **informants**).

### Information about Work Flow
How data moves through the system — methods, procedures, work schedules, and what happens to data at various processing points. Data Flow Diagrams (DFDs) are commonly used to map this flow.

---

## 3. Sources of Information

| Source Type | Examples |
|-------------|----------|
| **External** | Hardware/software vendors, government documents, professional journals (*Computerworld*, *Communications of the ACM*, *Journal for System Management*), software houses, consultant studies |
| **Internal** | User staff, financial reports, personnel records, system documentation, transaction documents, key informants |

> Modern addition: Online sources such as IEEE Xplore, ACM Digital Library, ResearchGate, and vendor documentation now supplement traditional external sources significantly.

---

## 4. Tool 1 — Review of Literature, Procedures, and Forms

### Overview
This is the **first step** in information gathering (Awad). Before interviewing or observing, the analyst reviews existing materials — procedures manuals, company studies, government publications, professional references, and printed forms. Very few system problems are unique; existing literature and software packages often provide ready solutions.

Key questions Awad recommends when reviewing **forms**:
1. Who uses the form? How important is it to the user?
2. Does the form include all necessary information? What should be added or deleted?
3. How many departments receive it, and why?
4. How readable and easy to follow is the form?
5. How does the information in the form help users make better decisions?

### Pros

| # | Advantage | Basis |
|---|-----------|-------|
| 1 | **Establishes baseline understanding** | Gives the analyst context before approaching users, reducing interview time. |
| 2 | **Reveals system requirements** | Procedures manuals describe the format, functions, and objectives of the present system. |
| 3 | **Identifies existing solutions** | Software packages and prior studies may already address the problem. |
| 4 | **Non-intrusive** | Does not consume user staff time during the review phase. |
| 5 | **Objective** | Documents reflect formal records, free from personal bias. |
| 6 | **Up-to-date manuals save hours** | When current, manuals can replace many rounds of interviewing. |

### Cons

| # | Disadvantage | Basis |
|---|--------------|-------|
| 1 | **Often outdated or missing** | Awad notes: *"in many cases, manuals do not exist or are seriously out of date."* |
| 2 | **Time-consuming search** | Obtaining reports is slow; publications may be expensive; information may lag reality. |
| 3 | **Incomplete coverage** | Informal practices and workarounds are rarely documented. |
| 4 | **No clarification possible** | Ambiguities in documents cannot be resolved without moving to interviews or observation. |
| 5 | **Volume overload** | Large organizations may have overwhelming amounts of documentation to process. |

> **Modern enrichment:** Digital document management systems (e.g., SharePoint, Confluence) now make document retrieval faster, but the problem of outdated content remains. Analysts today also review system logs, database schemas, and API documentation as part of this step.

---

## 5. Tool 2 — On-Site Observation

### Overview
On-site observation is *"the process of recognizing and noting people, objects, and events"* in the user's actual working environment (Awad). The analyst's role is that of a **detached information seeker** — not a consultant or judge. The major objective is to get as close as possible to the **"real" system** being studied.

Awad identifies four dimensions of observation methods:

| Dimension | Option A | Option B |
|-----------|----------|----------|
| Setting | **Natural** (workplace) | **Contrived** (lab/controlled) |
| Awareness | **Obtrusive** (subject knows) | **Unobtrusive** (e.g., one-way mirror) |
| Method | **Direct** (analyst watches) | **Indirect** (cameras, electronic recorders) |
| Structure | **Structured** (specific targets) | **Unstructured** (open-ended) |

> Electronic monitoring (e.g., truck fleet recorders tracking speed, idle time, and out-of-service time) is highlighted by Awad as an efficient modern form of indirect observation.

Awad's guiding questions for the observer:
1. What kind of system is it? What does it do?
2. Who runs it? Who are the key people?
3. What is the history of the system?
4. Is it a primary or secondary contributor to the organization? Fast-paced or slow to respond?

### Pros

| # | Advantage | Basis |
|---|-----------|-------|
| 1 | **Captures actual behavior** | Reveals what users *actually do*, not just what they *say* they do (Awad). |
| 2 | **Uncovers hidden processes** | Informal workflows and undocumented workarounds become visible. |
| 3 | **No memory dependency** | Analyst records real-time activities, not user recollections. |
| 4 | **Verifies other data** | Confirms or contradicts information from interviews and documents. |
| 5 | **Electronic methods are efficient** | Automated recorders provide speed, accuracy, and low cost (Awad). |

### Cons

| # | Disadvantage | Basis |
|---|--------------|-------|
| 1 | **Hawthorne Effect** | Staff may alter their behavior when they know they are being watched (Awad). |
| 2 | **Cannot capture mental processes** | Attitudes, motivations, and reasoning are not observable — *"only the actions that result from them"* (Awad). |
| 3 | **Observer bias** | The analyst's interpretation and subjective selection of what to observe introduces error. |
| 4 | **Time-consuming** | *"Unproductive, long hours are often spent in an attempt to observe specific, one-time activities"* (Awad). |
| 5 | **Disrupts the workplace** | Intruding into the user's area often results in adverse reactions from staff. |
| 6 | **Requires sampling discipline** | Without proper sampling, inferences from small time slices can be inaccurate (Awad). |

> **Modern enrichment:** Screen recording tools (e.g., session replay software like FullStory or Hotjar) and system usage logs now serve as indirect observation tools in software-heavy environments, reducing Hawthorne Effect and time cost.

---

## 6. Tool 3 — Interviews

### Overview
Awad defines the interview as *"a face-to-face interpersonal role situation in which a person called the interviewer asks a person being interviewed questions designed to gather information about a problem area."* It is the **oldest and most commonly used** information-gathering tool in systems work.

It serves two main purposes (Awad):
1. As an **exploratory device** — to identify relationships or verify information.
2. To **capture information as it currently exists**.

Interview schedules generally begin **at the top of the organization** and work downward, so as not to offend anyone.

### Awad's Four Primary Advantages of Interviews

> 1. **Flexibility** — superior for exploring areas where not much is known about what questions to ask.
> 2. **Validity assessment** — the interviewer can observe not only *what* subjects say but *how* they say it.
> 3. **Complex topics** — effective for probing sentiments underlying expressed opinions.
> 4. **Cooperation** — *"Many people enjoy being interviewed... they usually cooperate in a study when all they have to do is talk."* Return rates for questionnaires are often less than 20%.

### Awad's Guides to a Successful Interview

**1. Stage Setting** — Open by stating: (a) the purpose, (b) why the subject was selected, (c) the confidential nature. The analyst acts as a reporter, not a debater.

**2. Establishing Rapport** — Awad's key pitfalls to avoid:
- Do not mislead users about the study's purpose.
- Assure confidentiality — *"the promise of anonymity is very important."*
- Avoid personal involvement with any faction.
- Do not show off knowledge or share information from other sources.
- Respect time schedules; do not make it a social event.
- Do not interrupt — let the interviewee finish.

**3. Asking Questions** — In structured interviews, each question must be asked *exactly as worded* and *in the same order*. Rewording or resequencing destroys comparability.

**4. Probing** — When more detail is needed, the analyst uses neutral prompts:
- *"I see what you mean. Could you elaborate further on that?"*
- *"Can you tell me more about that?"*

**5. Data Recording (The Notebook)** — Awad stresses that *"many system studies fail because of poor data recording."* The notebook must include: all original notes (numbered, dated, with analyst's name), copies of all information-gathering tools, copies of all collected data, and minutes of all meetings.

### Pros

| # | Advantage | Basis |
|---|-----------|-------|
| 1 | **Flexible and exploratory** | Ideal when the analyst doesn't yet know what questions to ask (Awad). |
| 2 | **Validates information** | Non-verbal cues and tone help assess truthfulness (Awad). |
| 3 | **Handles complex subjects** | Can probe emotions, opinions, and underlying sentiments (Awad). |
| 4 | **High cooperation rate** | People prefer talking to writing; far better engagement than questionnaires (Awad). |
| 5 | **Immediate clarification** | Misunderstandings resolved on the spot. |

### Cons

| # | Disadvantage | Basis |
|---|--------------|-------|
| 1 | **Long preparation time** | The major drawback identified by Awad. |
| 2 | **Costly in time and money** | *"Whenever a more economical alternative captures the same information, the interview is generally not used"* (Awad). |
| 3 | **Risk of bias** | Rewording or resequencing questions can skew responses (Awad). |
| 4 | **Respondent distortion** | Fear of retaliation or reluctance to verbalize sensitive topics leads to invalid answers (Awad). |
| 5 | **Interviewing is an art** | Requires experience; poorly conducted interviews yield low-quality data. |

> **Modern enrichment:** Video interviews (Zoom, Teams) have extended the reach of interviewing to remote and distributed teams. Transcription tools (e.g., Otter.ai) address the documentation overhead. However, loss of in-person non-verbal cues remains a limitation in remote settings.

---

## 7. Tool 4 — Questionnaires

### Overview
A **questionnaire** is a self-administered tool used for almost any instrument that has questions to which individuals respond (Awad). It is especially powerful when the analyst needs to reach a **large number of users simultaneously**, or when anonymity encourages more honest responses.

### Five Types of Closed Questions (Awad)

| Type | Description | Example Use |
|------|-------------|-------------|
| **Fill-in-the-blank** | Requests specific facts | "What is the average number of calls you receive from clients?" |
| **Dichotomous** | Yes/No choice | "Are you personally using a microcomputer in your business?" |
| **Ranking scales** | Rank items by preference/importance | Rank 5 job characteristics from most to least descriptive |
| **Multiple-choice** | Select from given alternatives | "What is the average salary of an entry-level analyst?" |
| **Rating scales** | Rate items along a single dimension | Satisfaction scale 1–5 across job aspects |

**Open-ended questions** allow free-text responses. They are ideal for exploratory situations but are difficult to tabulate and prone to analyst bias in interpretation.

### Awad's Questionnaire Construction Procedure (6 Steps)

1. Define the problem — decide what data to collect.
2. Choose type — closed or open-ended.
3. Outline topics and write questions.
4. Edit for bias and technical defects.
5. **Pretest** the questionnaire — pilot it with a small group.
6. Final edit — review content, form, sequence, and instructions.

### Checklist for Question Design (Awad)

- **Content:** Is it necessary? Is it biased? Does the subject have the knowledge to answer?
- **Wording:** Appropriate for the subject's background? Can it be misinterpreted? Is framing uniform?
- **Format:** Is the response form easy to use? Does the prior question contaminate this one?

### Pros

| # | Advantage | Basis |
|---|-----------|-------|
| 1 | **Economical** | Requires less skill and time to administer than interviews (Awad). |
| 2 | **Large-scale reach** | Can be administered to many respondents simultaneously (Awad). |
| 3 | **Standardized** | Uniform wording and instructions ensure comparability across respondents (Awad). |
| 4 | **Anonymity** | Respondents feel freer to give honest answers without fear of identification (Awad). |
| 5 | **No immediate pressure** | Respondents have time to think and calculate before answering (Awad). |

### Cons

| # | Disadvantage | Basis |
|---|--------------|-------|
| 1 | **Low return rate** | *"Often less than 20 percent"* (Awad) — the principal disadvantage. |
| 2 | **No follow-up** | Unclear or incomplete answers cannot be clarified. |
| 3 | **Misinterpretation** | Questions may mean different things to different respondents. |
| 4 | **Respondent bias** | Respondents favor the first alternative in multiple-choice questions (Awad). |
| 5 | **Shallow open-ended data** | Free-text answers are rarely thorough; tedious to tabulate. |

> **Modern enrichment:** Online survey platforms (Google Forms, SurveyMonkey, Typeform) have significantly improved return rates through ease of use and automated reminders. However, survey fatigue and self-selection bias remain active concerns in modern practice.

---

## 8. Structured vs. Unstructured Approaches

Both interviews and questionnaires can be structured or unstructured. Awad summarizes the trade-offs as follows:

| Approach | Advantages | Drawbacks |
|----------|------------|-----------|
| **Structured** | Easy to administer and evaluate; requires limited training; easy to compare across respondents | High initial preparation cost; reduces spontaneity; can feel mechanical |
| **Unstructured** | Greater creativity and spontaneity; deeper understanding of feelings; more flexible | Gathers more data of questionable use; more time-consuming; requires extensive training and experience |

**Open-ended questions** suit exploratory phases where new ideas are sought.
**Closed questions** are more appropriate for factual information (age, salary, yes/no decisions) and are faster to tabulate.

---

## 9. Reliability and Validity of Information

Awad emphasizes that every information-gathering instrument must pass two critical tests:

### Reliability
Reliability means **dependability, consistency, and accuracy**. A reliable instrument produces the same or similar results when administered repeatedly under similar conditions. Awad identifies three sources of error that threaten reliability:

1. **Perceptual slant** — different staff members observing the same event report it differently.
2. **Memory failure** — details become harder to recall accurately over time.
3. **Reluctance to report truthfully** — fear of retaliation, desire not to upset others, or discomfort with verbalizing certain situations.
4. **Inability to communicate** — the subject knows the information but cannot articulate it clearly.

### Validity
Validity asks: *"Does the instrument measure what we think it is measuring?"* A questionnaire that tests factual knowledge of a billing system is **not valid** as a measure of employee *understanding* of that system — it measures something different from what was intended.

> **Key principle (Awad):** Reliability is a *necessary but not sufficient* condition for good results. High reliability does not guarantee validity, but there can be no good results without reliability.

---

## 10. Comparative Summary

| Tool | Primary Strength | Primary Weakness | Best Used When |
|------|-----------------|-----------------|----------------|
| Review of Literature & Forms | Non-intrusive baseline | Often outdated or missing | Starting a project; checking for existing solutions |
| On-Site Observation | Captures real behavior | Cannot observe attitudes/motivations | Verifying workflows; discovering informal practices |
| Interviews | Deep, flexible, valid | Time-consuming; expensive | Complex topics; small groups; when trust matters |
| Questionnaires | Economical; large-scale | Low return rate; no follow-up | Many users; anonymity needed; factual/statistical data |

**Combination strategy (Awad's implied workflow):**
1. Begin with **document/literature review** to understand the existing system.
2. Conduct **on-site observation** to see real workflows.
3. Use **interviews** with key staff to probe decision-making and requirements.
4. Deploy **questionnaires** to validate findings across a larger user population.

---

## 11. Conclusion

Information gathering is the analytical foundation of every system development project. Awad's framework presents four complementary tools — each with a distinct purpose, strength, and limitation. No single tool is universally sufficient. The analyst must choose and combine them based on the nature of the problem, the availability of users, cost constraints, and the type of information needed.

The deeper lesson from Awad is that beyond the mechanics of each tool lies an art — the art of interviewing, of unobtrusive observation, of crafting reliable and valid questionnaires. Technical knowledge of these tools is necessary, but skillful application of them is what separates a good analyst from a great one.

---

## 12. References

### Primary

1. **Awad, E. M.** *Systems Analysis and Design*. Richard D. Irwin Inc. / Galgotia Publications.
   - **Chapter 5: "Information Gathering"** — the primary and foundational reference for this entire assignment. Covers all four tools, interview guides, questionnaire construction, observation methods, and reliability-validity analysis.

### Supplementary Books

2. **Kendall, K. E., & Kendall, J. E.** (2019). *Systems Analysis and Design* (10th ed.). Pearson Education.
   - Extends Awad's coverage with JAD sessions, prototyping, and agile requirements elicitation.

3. **Dennis, A., Wixom, B. H., & Roth, R. M.** (2018). *Systems Analysis and Design* (6th ed.). John Wiley & Sons.
   - Covers modern structured walkthroughs and use-case driven requirements gathering.

4. **Satzinger, J. W., Jackson, R. B., & Burd, S. D.** (2016). *Systems Analysis and Design in a Changing World* (7th ed.). Cengage Learning.
   - Addresses requirements elicitation in agile and iterative development contexts.

### Online / Modern Sources

5. **Interaction Design Foundation.** *Requirements Gathering in UX.* https://www.interaction-design.org
   - Covers modern elicitation techniques including contextual inquiry and diary studies.

6. **Bourque, P., & Fairley, R. E. (Eds.).** (2014). *SWEBOK v3.0 — Guide to the Software Engineering Body of Knowledge.* IEEE Computer Society.
   - Chapter 1 covers requirements elicitation methods including interviews, observations, and prototyping in a software engineering context.

---

*End of Assignment*
