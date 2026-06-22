# Report On
# Library Management System

**Course Code: CSE-1202**
**Course Name: Object Oriented Programming Language Lab**

Submitted By

| Name | Registration No |
|---|---|
| Md. Imran Sajjad Sabbir | 2401011029 |
| Ziaur Rahman Farhad | 2401011032 |
| Md. Minhazul Haque | 2401011038 |

Session: 2024-25 &emsp; Group: 07

Under the supervision of

**DHONITA TRIPURA**
Assistant Professor of
Department of Computer Science and Engineering
Rangamati Science and Technology University

This Report is Submitted in Partial Fulfillment of the
Requirements for the Degree of B.Sc. (Engg.) in Computer Science and Engineering.

DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING
RANGAMATI SCIENCE AND TECHNOLOGY UNIVERSITY

Date of Submission: June 22, 2026

---

## APPROVAL

This report titled as "Library Management System", submitted by Md. Imran Sajjad Sabbir, Ziaur Rahman Farhad, and Md. Minhazul Haque (Group 07), to the Department of Computer Science and Engineering, Rangamati Science and Technology University has been accepted as satisfactory for the partial fulfillment of the requirements for the degree of B.Sc. (Engg.) in Computer Science and Engineering, and approved as to its style and contents.

**Board of Examiners**

Dhonita Tripura
Assistant Professor
Department of Computer Science and Engineering
Rangamati Science and Technology University &emsp; Supervisor

---

## DECLARATION

We, Md. Imran Sajjad Sabbir, Ziaur Rahman Farhad, and Md. Minhazul Haque, do hereby declare that this report has been done by us under the supervision of Dhonita Tripura, Assistant Professor, Department of Computer Science and Engineering, Rangamati Science and Technology University. We also declare that neither this report nor any part of this report has been submitted elsewhere for the award of any degree.

**Submitted By**

Group 07

Md. Imran Sajjad Sabbir (Reg: 2401011029),
Ziaur Rahman Farhad (Reg: 2401011032),
Md. Minhazul Haque (Reg: 2401011038)

Session: 2024-25
Department of Computer Science and Engineering
Rangamati Science and Technology University

---

## ACKNOWLEDGEMENT

First of all, we would like to express our gratitude to the Almighty for enabling us to complete this project titled "Library Management System". We are deeply grateful to our Academic Supervisor, Dhonita Tripura, Assistant Professor, Department of Computer Science and Engineering, Rangamati Science and Technology University, for her continuous guidance, feedback, and academic review throughout this course (CSE-1202: Object Oriented Programming Language Lab).

We would also like to thank our fellow classmates for their constructive suggestions during the review phase, and all the course teachers who supported us throughout this semester. Finally, we thank our group members for the collaboration, shared ownership, and consistent effort that made this project possible.

Group 07

---

## Table of Contents

| Section | Title | Page |
|---|---|---|
| | APPROVAL | i |
| | DECLARATION | ii |
| | ACKNOWLEDGEMENT | iii |
| | List of Tables | vi |
| | List of Figures | vii |
| | List of Acronyms | viii |
| | ABSTRACT | ix |
| **1** | **Introduction** | **1** |
| 1.1 | Overview | 1 |
| 1.2 | Motivation of the Project | 1 |
| 1.3 | Problem Statement | 1 |
| 1.4 | Project Gap | 2 |
| 1.5 | Objectives | 2 |
| 1.6 | Scope of the Project | 2 |
| 1.7 | Contributions | 2 |
| 1.8 | Organization of the Report | 2 |
| **2** | **Literature Review** | **3** |
| 2.1 | Background | 3 |
| 2.2 | Limitations of Legacy Library Systems | 3 |
| 2.3 | Role-Based Access in Library Applications | 3 |
| 2.4 | Visual Seat Allocation in Academic Environments | 3 |
| 2.5 | Summary | 3 |
| **3** | **Methodology** | **4** |
| 3.1 | Development Methodology | 4 |
| 3.2 | Requirements Engineering | 5 |
| 3.2.1 | Stakeholder Analysis | 5 |
| 3.2.2 | Functional Requirements | 5 |
| 3.2.3 | Non-Functional Requirements | 6 |
| 3.2.4 | MoSCoW Prioritization | 6 |
| 3.3 | System Modeling | 7 |
| 3.3.1 | Context Diagram (Level 0 DFD) | 7 |
| 3.3.2 | Level 1 DFD — Main Processes | 8 |
| 3.3.3 | Level 2 DFD — Book Transaction Process | 8 |
| 3.3.4 | Use Case Diagram | 9 |
| 3.3.5 | Activity Diagram — Book Issue Workflow | 10 |
| 3.3.6 | Sequence Diagram — Seat Reservation | 10 |
| 3.3.7 | Class Diagram (Simplified) | 11 |
| 3.4 | Database Design | 12 |
| 3.4.1 | Entity Relationship Diagram | 12 |
| 3.4.2 | Schema Design Rationale | 13 |
| 3.4.3 | Data Model Description | 13 |
| 3.4.4 | Three-Tier Architecture | 14 |
| 3.4.5 | Architecture Decisions | 15 |
| 3.5 | User Interface / User Experience Design | 16 |
| 3.5.1 | Design Principles | 16 |
| 3.5.2 | Layout and Theming | 16 |
| 3.5.3 | Key User Flows | 18 |
| 3.6 | Technology Stack | 19 |
| 3.7 | Key Algorithms | 20 |
| 3.7.1 | Algorithm 1: Seat Reservation State Update | 20 |
| 3.7.2 | Algorithm 2: Book Availability Reconciliation | 20 |
| **4** | **Results and Discussion** | **21** |
| 4.1 | Implementation Summary | 21 |
| 4.2 | Testing Strategy | 21 |
| 4.2.1 | Test Case Summary | 21 |
| 4.3 | Evaluation Against Objectives | 22 |
| 4.4 | Discussion | 22 |
| 4.5 | Limitations Identified During Testing | 22 |
| **5** | **Limitations and Future Work** | **23** |
| 5.1 | Current Limitations | 23 |
| 5.2 | Future Work | 23 |
| **6** | **Conclusion** | **24** |
| | References | 25 |

---

## List of Tables

| No. | Title | Page |
|---|---|---|
| 1 | Development Phase Plan | 4 |
| 2 | Incremental Feature Plan | 4 |
| 3 | Stakeholder Identification | 5 |
| 4 | MoSCoW Requirement Prioritization | 6 |
| 5 | Context Diagram Data Flow Summary | 7 |
| 6 | Use Case Summary by Actor | 9 |
| 7 | Entity Attribute Summary | 13 |
| 8 | Technology Stack Summary | 19 |
| 9 | Test Case Summary (16/16 Passed) | 21 |
| 10 | Objective Evaluation | 22 |

---

## List of Figures

| No. | Title | Page |
|---|---|---|
| 1 | Development Phase Timeline (Gantt View) | 4 |
| 2 | Context Diagram (Level 0 DFD) | 7 |
| 3 | Level 1 DFD — Main Processes | 8 |
| 4 | Level 2 DFD — Book Transaction Process (Expansion of P3) | 8 |
| 5 | Use Case Diagram (Principal Actors and Use Cases) | 9 |
| 6 | Activity Diagram — Book Issue Workflow | 10 |
| 7 | Class Diagram (Simplified) | 11 |
| 8 | Entity Relationship Diagram | 12 |
| 9 | Three-Tier System Architecture | 14 |
| 10 | Architecture Decisions and Rationale | 15 |
| 11 | Shared Application Shell — Dark Theme Layout | 16 |
| 12 | Administrative Dashboard Screen | 17 |
| 13 | Book Inventory Management Screen | 17 |
| 14 | Interactive Computerized Seat-Finding Map | 18 |
| 15 | Student Catalog Search Portal | 18 |
| 16 | Visualization of the Four Primary User Workflows | 19 |

---

## List of Acronyms

| Acronym | Full Form |
|---|---|
| RMSTU | Rangamati Science and Technology University |
| LMS | Library Management System |
| OOP | Object Oriented Programming |
| OOD | Object Oriented Design |
| JDK | Java Development Kit |
| GUI | Graphical User Interface |
| JDBC | Java Database Connectivity |
| CRUD | Create, Read, Update, Delete |
| DFD | Data Flow Diagram |
| UML | Unified Modeling Language |
| ERD | Entity Relationship Diagram |
| RBAC | Role-Based Access Control |
| SDLC | Software Development Life Cycle |
| MoSCoW | Must have, Should have, Could have, Won't have |
| PK / FK | Primary Key / Foreign Key |
| AWT | Abstract Window Toolkit |
| SRS | Software Requirements Specification |
| UAT | User Acceptance Testing |
| FR | Functional Requirement |
| NFR | Non-Functional Requirement |

---

## ABSTRACT

The Library Management System (LMS) is an interactive, desktop-based application engineered on the Java Standard Edition (Java SE) platform and rendered through the Java Swing graphical toolkit. The system is architected to streamline three principal institutional workflows: bibliographic book indexing, member (student) lifecycle tracking, and real-time physical space allocation within academic study halls. Traditional library operations have historically depended upon manual artifacts — paper-bound logbooks, physical paper tokens for issuance, and loosely structured spreadsheets — which collectively introduce structural inefficiencies, propagate human transcription errors, and lack any mechanism for real-time observation of study-seat availability.

This project addresses those deficiencies by integrating a robust object-oriented backend, governed by encapsulation, inheritance, and polymorphism, with an automated, visually rendered desktop interface. The application consolidates administrative book management, secure role-based authentication, and an advanced Computerized Seat-Finding Module that translates abstract availability data into a color-coded visual matrix. By unifying these capabilities within a single, locally executing desktop binary, the system measurably lowers administrative burdens, eliminates redundant data entry, and optimizes the spatial utilization of the library environment.

**Keywords:** Library management system, Java Swing, object-oriented design, role-based access control, computerized seat-finding, desktop application, JDBC, MySQL.

---

# Chapter 1

# Introduction

## 1.1 Overview

At Rangamati Science and Technology University (RMSTU), library operations are managed largely through a manual process — books catalogued on paper ledgers, member records maintained in disconnected notebooks, and study-seat availability determined only by physically walking through the reading hall. This project, the Library Management System, is a desktop-based, object-oriented application that digitizes the complete library workflow: book cataloguing and CRUD management by the librarian, student member registration, issue and return transaction processing, and real-time visual seat allocation through an interactive graphical module.

## 1.2 Motivation of the Project

The motivation for this project stems from recurring pain points in RMSTU's current manual library workflow:

- Students have no way to check seat availability without physically entering the reading hall.
- Librarians record every book issuance and return by hand, making transcription errors difficult to detect.
- Member records are maintained on paper, with no audit trail for who borrowed which book.
- Administrators have no centralized mechanism to track stock levels or pending returns.
- Study space is chronically underutilized because students cannot determine vacancy from outside the hall.

## 1.3 Problem Statement

The manual library management process at RMSTU produces six concrete pain points:

1. Paper-based book cataloguing introduces risk of loss, damage, or illegible entries.
2. Manual issue and return recording is prone to duplication and arithmetic errors.
3. No role-based access control exists to restrict administrative functions from the general student view.
4. No audit trail records which librarian processed which transaction and at what time.
5. Book availability and seat availability are maintained in separate, disconnected systems.
6. No visual mechanism exists for students to determine real-time seat vacancy without a physical survey.

## 1.4 Project Gap

Most simple library software implementations either use non-relational flat files that corrupt historical records when catalog data changes, or provide only a basic catalog without any spatial allocation feature. No surveyed open-source or legacy solution combines full administrative CRUD, secure role differentiation, and an interactive visual seat-management module within a single offline desktop application. This project integrates all three mechanisms into one cohesive, locally executing artifact.

## 1.5 Objectives

This project follows five objectives stratified into primary and secondary tiers:

1. Engineer a stable, fully object-oriented desktop application that automates the library catalog and the administrative transaction cycle (issue and return), eliminating manual ledger dependency.
2. Establish distinct user tiers — a privileged Librarian/Administrator view and a restricted Student/Public view — through polymorphic role differentiation.
3. Enforce strict data structural integrity, ensuring every transaction is referentially consistent with its associated book and member records.
4. Engineer a visual matrix that maps the physical library study-hall layout into addressable coordinate slots, enabling real-time tracking, reservation, and clearance of individual seats.
5. Implement a cohesive, modern dark-themed user interface that maintains visual consistency and reduces ocular strain during prolonged administrative sessions.

## 1.6 Scope of the Project

**In Scope:** Role-based authentication (Librarian/Admin and Student roles); full book catalog CRUD; student member registration and management; book issue and return transaction processing with immediate availability reconciliation; interactive color-coded seat-finding module; local data persistence via MySQL/JDBC or serialized file handling; and a dark-themed Java Swing graphical interface.

**Out of Scope:** Web or mobile access, online reservation from outside the campus network, barcode or RFID hardware integration, automated email notifications, fine/fee management, multi-branch library support, and integration with external academic systems.

## 1.7 Contributions

1. Design and implementation of a Computerized Seat-Finding Module that renders the study-hall floor plan as an interactive color-coded grid, allowing students to determine seat availability at a single glance.
2. Design of a polymorphic role-differentiation scheme (Admin vs. Student) derived from a common abstract User superclass, enabling clean privilege separation.
3. Implementation of a real-time observer-driven repaint mechanism that synchronizes the in-memory seat-state two-dimensional array with its visual rendering on every state mutation.
4. A referentially consistent relational schema linking bibliographic records, member identities, transaction logs, and physical seat coordinates within a single data model.

## 1.8 Organization of the Report

Chapter 2 reviews related work. Chapter 3 covers methodology including requirements, system modeling, database design, and architecture. Chapter 4 presents results and testing. Chapter 5 discusses limitations and future work. Chapter 6 concludes.

---

# Chapter 2

# Literature Review

## 2.1 Background

Library information systems broadly fall into three categories:

1. Fully manual or paper-ledger-based processes.
2. Simple flat-file or spreadsheet-based desktop tools.
3. Comprehensive web-based Integrated Library Systems (ILS), which are feature-rich but expensive and often poorly suited to offline institutional contexts.

## 2.2 Limitations of Legacy Library Systems

Most simple library tools use a single, non-relational flat file or spreadsheet per entity, where records are directly overwritten when book metadata or member details change. This introduces a critical flaw: transaction history silently loses context because the original bibliographic or member record may no longer exist in its original form. Furthermore, spreadsheet solutions offer no concurrent-access safety, no role separation, and no programmatic validation of data entry.

## 2.3 Role-Based Access in Library Applications

Library applications require at minimum two distinct access tiers: an administrative tier for catalog management and transaction processing, and a read-only public tier for catalog browsing and reservation status checking. Naive implementations hard-code a single interface for all users. This project instead defines polymorphic Admin and Student subclasses derived from a common abstract User superclass, enabling role-dependent behavior dispatch through a secure credential-verification gateway.

## 2.4 Visual Seat Allocation in Academic Environments

A persistent and well-documented pain point in academic libraries is the absence of any mechanism for determining seat availability without physical inspection. Prior open-source ILS solutions such as Koha offer comprehensive catalog management over a web interface but provide no spatial allocation feature whatsoever. This project addresses that gap directly through the Computerized Seat-Finding Module — a bespoke Java Swing component that renders a dynamically redrawn, color-coded grid of the study-hall floor plan.

## 2.5 Summary

Existing library systems typically lack at least one of the following: offline desktop operation, fine-grained role-based access control, and interactive visual seat management. This project combines all three into one cohesive desktop artifact, occupying a niche unaddressed by the surveyed alternatives.

---

# Chapter 3

# Methodology

## 3.1 Development Methodology

The system was developed using an Iterative and Incremental model, executed across four structured development phases of approximately two weeks each, for a total project duration of eight weeks. Table 1 summarizes the phase plan.

**Table 1: Development Phase Plan**

| Phase | Focus |
|---|---|
| Phase 1 (Weeks 1–2) | Project setup, class hierarchy design, authentication module |
| Phase 2 (Weeks 3–4) | Book catalog CRUD, member registration, data persistence layer |
| Phase 3 (Weeks 5–6) | Issue/return transaction processing, seat-finding module |
| Phase 4 (Weeks 7–8) | UI polish, integration testing, documentation |

Figure 1 presents the same plan as a timeline, showing how the four phases' workstreams overlap across the eight-week schedule.

```
W1   W2   W3   W4   W5   W6   W7   W8
Setup & Auth      |====|
Book CRUD                |====|
Transaction + Seat             |====|
UI Polish + Testing                  |====|
```

**Figure 1: Development Phase Timeline (Gantt View)**

The system was further decomposed into five increments (Table 2), each corresponding to one of the functional workstream bars in Figure 1.

**Table 2: Incremental Feature Plan**

| # | Increment | Scope |
|---|---|---|
| 1 | Auth + Role Framework | Credential verification, Admin/Student role dispatch |
| 2 | Book Catalog | Full CRUD on bibliographic records, catalog search |
| 3 | Member & Transactions | Member registration, book issue and return with availability update |
| 4 | Seat-Finding Module | Interactive color-coded seat grid, reserve and clear operations |
| 5 | UI Polish | Dark-theme consistency, input validation, end-to-end integration |

## 3.2 Requirements Engineering

### 3.2.1 Stakeholder Analysis

Table 3 identifies the system's primary, secondary, and external stakeholders.

**Table 3: Stakeholder Identification**

| ID | Stakeholder | Interaction |
|---|---|---|
| S1 | Librarian / Administrator | Full access: manage catalog, members, transactions, and seat allocations |
| S2 | Student / Public User | Browse catalog, check personal reservation status, view seat availability |
| S3 | University Management | Consume summary reports of stock levels and transaction history |
| S4 | IT Support Staff | Install and maintain the desktop application on institutional workstations |

### 3.2.2 Functional Requirements

Functional requirements are grouped into six categories covering the full operational lifecycle from authentication to seat allocation.

- **Authentication and Role Management (FR-01–FR-03):** Credential-based login for Librarian and Student roles; role-appropriate interface dispatch on successful authentication; session logout with state cleanup.

- **Book Catalog Management (FR-04–FR-09):** Create new bibliographic records (title, author, genre, identifier, availability); read and display the full catalog in a JTable grid; update existing record metadata; delete deprecated or deaccessioned records; multi-variable catalog search by title, author, genre, or identifier.

- **Member Management (FR-10–FR-13):** Register new student member accounts with structurally validated fields; read and display the member list; update member profile details; and delete inactive member records.

- **Transaction Processing (FR-14–FR-17):** Issue a book to a registered member with immediate availability flag update; process a book return with immediate reinstatement of availability; prevent issuance of an already-issued book; maintain a transaction log recording book identifier, member identifier, issue date, return date, and status.

- **Computerized Seat-Finding Module (FR-18–FR-22):** Render an interactive visual grid representing the study-hall floor plan; display real-time occupancy status per seat through color coding; allow a student to reserve an available seat; allow a librarian to force-clear any reserved or occupied seat; dynamically repaint the grid on every state change without application restart.

- **Student/Public View (FR-23–FR-25):** Multi-variable catalog search; reservation and borrowing status inspection; read-only access to personal member details.

### 3.2.3 Non-Functional Requirements

Non-functional requirements define the quality constraints under which the system must operate.

- **Performance:** Catalog and seat queries shall resolve with imperceptible latency under typical institutional dataset sizes.
- **Availability:** The application shall execute reliably as a standalone desktop binary, independent of network connectivity.
- **Security:** Admin credential fields shall be backed by encapsulated private accessors; student records shall not be accessible without authentication.
- **Usability:** Core workflows — issue a book, return a book, find a seat — shall be completable within three user interactions.
- **Maintainability:** The codebase shall observe separation of the data-model layer from the presentation layer so that interface changes do not perturb business logic.
- **Portability:** The application shall execute on any workstation with a standard JRE installation, without recompilation.
- **Data Integrity:** Every transaction shall maintain referential consistency between BOOK, STUDENT, and TRANSACTION records.

### 3.2.4 MoSCoW Prioritization

Table 4 classifies all requirements by priority using the MoSCoW method.

**Table 4: MoSCoW Requirement Prioritization**

| Priority | Requirements |
|---|---|
| Must Have | Authentication; book catalog CRUD; member registration; issue and return transaction processing; seat-finding visual module; student portal |
| Should Have | Multi-variable catalog search; transaction log viewing; bulk seat clearance by librarian |
| Could Have | Data export to CSV; fine/due-date tracking; borrowing history per member |
| Won't Have | Web or mobile access; barcode/RFID hardware integration; email notifications; multi-branch support |

## 3.3 System Modeling

### 3.3.1 Context Diagram (Level 0 DFD)

A Context Diagram (Level 0 DFD) represents the entire system as a single process, defines its boundary, and shows all external entities that interact with it — without describing any internal logic.

Figure 2 shows the three external entities and their primary data flows with the Library Management System.

```
                    Library Management System

Admin / Librarian ─────► Login, Book CRUD, Issue/Return, Seat Management
Student ──────────────► Login, Catalog Search
Student ◄─────────────── Published Catalog, Seat Availability, Reservation Status
University Mgmt ◄──────── Summary Reports, Transaction Logs
```

**Figure 2: Context Diagram (Level 0 DFD)**

Table 5 summarizes each data flow shown in the diagram.

**Table 5: Context Diagram Data Flow Summary**

| Flow | Source | Destination | Data |
|---|---|---|---|
| F1 | Admin | System | Login credentials, book records, member records, transaction commands |
| F2 | Student | System | Login credentials, catalog search queries, seat reservation requests |
| F3 | System | Student | Catalog results, seat availability grid, borrowing status |
| F4 | System | University Management | Transaction logs, stock summary reports |

### 3.3.2 Level 1 DFD — Main Processes

Figure 3 decomposes the system into four major processes, each responsible for a distinct functional domain. Data flows from external users through authentication into catalog management, member management, and finally transaction and seat processing.

```
Users
  │
  ▼
P1: Authentication ──► D1: Users/Roles
  │
  ├──► P2: Book Catalog Management ──► D2: Book Records
  │
  ├──► P3: Member Management ──────── D3: Member Records
  │
  └──► P4: Transactions & Seats ───── D4: Transactions / SeatMatrix
```

**Figure 3: Level 1 DFD — Main Processes**

### 3.3.3 Level 2 DFD — Book Transaction Process (P3 Expansion)

Figure 4 expands P4 into its sequential sub-processes, illustrating how a book issuance progresses from member verification through availability checking before the transaction record is committed and the catalog availability flag is updated.

```
Verify Member ──► Check Availability ──► Issue Book ──► Update Availability ──► Log Transaction
```

**Figure 4: Level 2 DFD — Book Transaction Process (Expansion of P3)**

### 3.3.4 Use Case Diagram

Figure 5 presents the principal use cases grouped by actor, with each actor's interactions bounded by their assigned role permissions.

```
 ⃝ Admin/Librarian:
        Manage Book Catalog (CRUD)
        Register / Manage Members
        Process Issue and Return
        Force-Clear Seat Reservations
        View Transaction Logs

 ⃝ Student:
        Search Catalog
        Reserve a Seat
        View Borrowing Status
        View Personal Profile
```

**Figure 5: Use Case Diagram (Principal Actors and Use Cases)**

Table 6 summarizes each actor's use cases and the permission scope under which they operate.

**Table 6: Use Case Summary by Actor**

| Actor | Use Cases | Permission Scope |
|---|---|---|
| Admin / Librarian | Book CRUD; member management; issue/return processing; seat force-clear; transaction log view | Full system access |
| Student | Catalog search; seat reservation; borrowing and reservation status view; profile view | Own records only; read-only catalog; seat reservation for self |

### 3.3.5 Activity Diagram — Book Issue Workflow

Figure 6 models the book issuance activity, including the availability decision branch.

```
Librarian Initiates Issue
        │
        ▼
  Verify Member Exists?
   Yes ──► Check Book Availability
              │
    Available ──► Create Transaction Record
                      │
                      ▼
              Update Book Availability to FALSE
                      │
                      ▼
              Refresh JTable Catalog Grid
   Not Available ──► Display Error: Book Already Issued
```

**Figure 6: Activity Diagram — Book Issue Workflow**

### 3.3.6 Sequence Diagram — Seat Reservation

The seat reservation sequence proceeds as: student clicks an available seat cell on the Swing grid → ActionListener intercepts the click → system checks current occupancyState of the selected SeatMatrix cell → if FREE, state is updated to RESERVED and studentID is recorded → repaint() is invoked on the grid panel → updated color-coded cell is rendered → confirmation displayed to the student.

If the selected seat is already RESERVED or OCCUPIED, the system displays a rejection message and no state change is applied.

### 3.3.7 Class Diagram (Simplified)

Figure 7 illustrates the core class hierarchy and principal associations that form the object-oriented backbone of the system.

```
         ┌──────────────┐
         │  <<abstract>> │
         │     User      │
         │  userID       │
         │  username     │
         │  passwordHash │
         │  +login()     │
         └──────┬───────┘
                │ extends
       ┌────────┴──────────┐
       │                   │
  ┌────┴─────┐       ┌─────┴──────┐
  │  Admin   │       │  Student   │
  │+manageCatalog()  │+searchCatalog()
  │+processIssue()   │+reserveSeat()
  │+clearSeat() │    └────────────┘
  └────────────┘

  ┌──────────┐   issues/returns  ┌─────────────┐
  │  Admin   │──────────────────►│ Transaction │
  └──────────┘                   │ txnID       │
                                 │ bookID (FK) │
  ┌──────────┐  participates in  │studentID(FK)│
  │ Student  │──────────────────►│ issueDate   │
  └──────────┘                   │ returnDate  │
                                 │ status      │
  ┌──────────┐  references       └──────┬──────┘
  │   Book   │◄──────────────────────── │
  │ bookID   │                          │
  │ title    │
  │ author   │    reserves
  │ genre    │  ┌───────────┐
  │availability  │ SeatMatrix│
  └──────────┘  │ seatID    │
   ◄────────────│ rowCoord  │
  Student       │ colCoord  │
                │occupancyState
                └───────────┘
```

**Figure 7: Class Diagram (Simplified)**

## 3.4 Database Design

### 3.4.1 Entity Relationship Diagram

Figure 8 illustrates the core entity structure of the database. The relational schema comprises five entities: ADMIN, STUDENT, BOOK, TRANSACTION, and SEATMATRIX. Foreign-key constraints bind transaction logs to both book and member records and link member identity to physical seat coordinates, unifying bibliographic, member, and spatial domains within a single referential graph.

```
┌──────────────┐  issues/returns  ┌──────────────┐
│    ADMIN     │─────────────────►│ TRANSACTION  │
├──────────────┤                  ├──────────────┤
│ adminID (PK) │                  │ txnID (PK)   │
│ username     │                  │ bookID (FK)  │
│ passwordHash │                  │studentID (FK)│
└──────────────┘                  │ issueDate    │
                                  │ returnDate   │
┌──────────────┐  participates in │ status       │
│   STUDENT    │─────────────────►└──────────────┘
├──────────────┤                        ▲
│studentID (PK)│                        │ references
│ name         │                  ┌─────┴────────┐
│ email        │                  │    BOOK      │
│ seatRef (FK) │──────┐           ├──────────────┤
└──────────────┘      │           │ bookID (PK)  │
                      │ reserves  │ title        │
                      ▼           │ author       │
              ┌──────────────┐    │ genre        │
              │  SEATMATRIX  │    │ availability │
              ├──────────────┤    └──────────────┘
              │ seatID (PK)  │
              │ rowCoord     │
              │ colCoord     │
              │occupancyState│
              └──────────────┘
```

**Figure 8: Entity Relationship Diagram**

### 3.4.2 Schema Design Rationale

The relational schema is normalized to the third normal form to eliminate data redundancy and enforce referential integrity. Each entity is assigned a dedicated primary key. Foreign-key relationships in TRANSACTION bind every borrowing record to exactly one BOOK and one STUDENT record, preventing orphaned transactions. The STUDENT.seatRef foreign key links member identity to SEATMATRIX.seatID, ensuring that a seat reservation is always associated with a verifiable member account. Book availability is stored as a boolean flag in BOOK and is atomically updated on every issue and return operation.

### 3.4.3 Data Model Description

Table 7 summarizes the attributes and roles of each entity in the schema.

**Table 7: Entity Attribute Summary**

| Entity | Key Attributes | Role |
|---|---|---|
| BOOK | bookID (PK), title, author, genre, availability | Bibliographic catalog record; availability flag controls issuance eligibility |
| STUDENT | studentID (PK), name, email, seatRef (FK) | Member identity record; seatRef links to current seat reservation |
| ADMIN | adminID (PK), username, passwordHash | Encapsulated librarian credential record |
| TRANSACTION | txnID (PK), bookID (FK), studentID (FK), issueDate, returnDate, status | Audit log of all issue and return events |
| SEATMATRIX | seatID (PK), rowCoord, colCoord, occupancyState | Physical layout model; occupancyState drives the visual grid rendering |

### 3.4.4 Three-Tier Architecture

Figure 9 illustrates the three-tier architecture of the system.

```
Client Tier
  Java Swing (JFrame, JPanel, JTable, JButton)
  AWT Layout Managers (GridBagLayout, BorderLayout)
  ActionListener Event Handlers
  Custom paintComponent for Seat Grid

         │  ActionEvents / Data Calls
         ▼

Business Logic Tier
  OOP Class Hierarchy (User, Admin, Student, Book, Transaction, SeatMatrix)
  Collections Framework (ArrayList, HashMap, 2D Array for seat state)
  Input Validation (Regex-based field sanitization)
  Role-Dispatch Logic

         │  JDBC Calls / Serialized I/O
         ▼

Data Tier
  MySQL (via JDBC) or Local Serialized File Handling
  Normalized Tables: BOOK, STUDENT, ADMIN, TRANSACTION, SEATMATRIX
```

**Figure 9: Three-Tier System Architecture**

### 3.4.5 Architecture Decisions

Figure 10 summarizes the five key architectural decisions and their rationale.

```
Desktop (Java SE + Swing)
  Offline operation; cross-platform JRE deployment; no network dependency.

OOP Class Hierarchy
  Clean role separation; Admin and Student extend abstract User superclass.

Collections Framework
  ArrayList for catalog; 2D boolean array for seat-state tracking.

Observer-Driven Repaint
  repaint() triggered on every seat-state mutation guarantees visual coherence.

MySQL via JDBC
  Relational integrity; normalized schema; persistent across sessions.
```

**Figure 10: Architecture Decisions and Rationale**

## 3.5 User Interface / User Experience Design

### 3.5.1 Design Principles

The interface follows five principles: simplicity (core tasks in three interactions or fewer), consistency (uniform dark-theme palette across all screens), clear role distinction (visually distinct navigation for Librarian vs. Student), responsiveness (dynamic redraws without application restart), and accessibility (high-contrast neon-emerald on charcoal backgrounds, amber typography for labels).

### 3.5.2 Layout and Theming

All authenticated screens share a fixed-position navigation rail anchored to the west via BorderLayout, a content viewport at the center, and action controls positioned at the south. A charcoal/midnight-black backdrop is accented exclusively with amber, gold, and neon-emerald green throughout. No blue or pink elements appear on any screen. The color palette is defined as constant fields in a shared ThemeConstants class, enabling palette-wide updates from a single location.

**Figure 11: Shared Application Shell — Dark Theme Layout**
*(Sidebar navigation rail, west-anchored | Central content viewport | South action controls)*

**Admin Dashboard:** The administrative dashboard presents a unified navigation panel. Control icons are rendered in contrasting gold against deep-gray containers, with menu labels in amber typography. Quick-access buttons surface the four most common administrative operations: Add Book, Issue Book, Return Book, and Manage Seats.

**Figure 12: Administrative Dashboard Screen**
*(Dark charcoal backdrop; gold navigation icons; amber labels; quick-access CRUD buttons in neon-emerald green)*

**Book Inventory Manager:** A JTable data grid displays the complete book catalog with gold column headers over a midnight-black surface. Full CRUD operations are exposed through neon-emerald green action buttons positioned beneath the grid. A search bar above the table supports multi-variable filtering by title, author, genre, or identifier.

**Figure 13: Book Inventory Management Screen**
*(JTable with gold headers; midnight-black surface; neon-emerald CRUD action buttons; amber search field)*

**Interactive Computerized Seat-Finding System:** A visual seating map renders the study-hall floor plan as a grid of color-coded boxes. Occupied slots appear in muted dark gray, reserved slots in amber, and available seats in vibrant neon-emerald green. A legend annotates the three occupancy states. Clicking any available cell triggers a reservation; librarians see an additional Force Clear option on any occupied or reserved cell.

**Figure 14: Interactive Computerized Seat-Finding Map**
*(Color-coded seat grid: neon-emerald = Free, amber = Reserved, dark gray = Occupied; amber legend; Force Clear button for admin)*

**Student Catalog Portal:** The student-facing view presents the catalog search interface with a multi-field query bar and results rendered in a read-only JTable. A separate tab surfaces the seat-finding grid and the student's current reservation status.

**Figure 15: Student Catalog Search Portal**
*(Read-only catalog JTable; multi-variable search bar; seat grid tab; personal reservation status panel)*

### 3.5.3 Key User Flows

Figure 16 visualizes the four primary user workflows within the Library Management System.

```
Librarian — Issue Book          Librarian — Return Book
  Login                           Login
  Dashboard                       Dashboard
  Select Member                   Select Transaction Record
  Select Book                     Confirm Return
  Confirm Issue                   Availability Restored
  Availability Updated

Student — Find a Seat           Student — Search Catalog
  Login                           Login
  Dashboard                       Dashboard
  Open Seat Map                   Enter Search Query
  Click Available Seat            Browse Results
  Reservation Confirmed           View Book Details
```

**Figure 16: Visualization of the Four Primary User Workflows**

## 3.6 Technology Stack

Table 8 summarizes the technology choices across all tiers.

**Table 8: Technology Stack Summary**

| Layer | Technology | Purpose |
|---|---|---|
| Backend Logic | Java Development Kit (JDK) | Encapsulates business logic, inheritance structures, and the Collections Framework |
| Presentation | Java Swing & AWT | JFrame, JPanel, JTable, JButton; GridBagLayout and BorderLayout composition |
| Design Paradigm | Object-Oriented Design (OOD) | Encapsulation, Inheritance, Polymorphism, and Abstraction across the codebase |
| Persistence | MySQL via JDBC / Local File Handling | Stores relational tables and structural records across sessions |
| Build Tool | Java SE SDK / IDE (IntelliJ / Eclipse) | Compilation, packaging, and local execution |
| Version Control | Git + GitHub | Source control and team collaboration |

## 3.7 Key Algorithms

### 3.7.1 Algorithm 1: Seat Reservation State Update

1. **Input:** Selected seat cell (rowCoord, colCoord), requesting studentID
2. Retrieve the current occupancyState of SEATMATRIX at (rowCoord, colCoord)
3. **If** occupancyState == FREE:
   - Set occupancyState = RESERVED
   - Record studentID against that seatID
   - Update STUDENT.seatRef = seatID for the requesting student
   - Invoke repaint() on the Swing seat-grid panel
4. **Else:** Display rejection dialog ("Seat already occupied or reserved")
5. **Output:** Updated seat grid; updated SEATMATRIX and STUDENT records

### 3.7.2 Algorithm 2: Book Availability Reconciliation

1. **Input:** bookID, studentID, operation (ISSUE or RETURN)
2. **If** operation == ISSUE:
   - Query BOOK.availability for bookID
   - **If** availability == TRUE:
     - Set BOOK.availability = FALSE
     - Insert TRANSACTION record (bookID, studentID, issueDate = NOW(), status = ISSUED)
   - **Else:** Display error ("Book currently issued to another member")
3. **If** operation == RETURN:
   - Locate open TRANSACTION record where bookID matches and status == ISSUED
   - Set TRANSACTION.returnDate = NOW(), TRANSACTION.status = RETURNED
   - Set BOOK.availability = TRUE
4. **Output:** Updated BOOK record; committed TRANSACTION record; refreshed JTable catalog grid

---

# Chapter 4

# Results and Discussion

## 4.1 Implementation Summary

The application was implemented as a single-workstation Java SE desktop binary. All Swing components rendered consistently within the prescribed dark-theme palette. The Admin panel exposed full CRUD controls across the book catalog and member list, and transaction processing correctly updated availability flags in real time. The Computerized Seat-Finding Module rendered and dynamically refreshed the color-coded matrix on every reservation and clearance event, confirming the viability of the observer-driven repaint approach. Role-based authentication correctly segregated administrative and student privileges across all screens.

## 4.2 Testing Strategy

Testing was conducted at four levels: unit (availability reconciliation logic and seat-state transitions), integration (JDBC persistence layer against the database), RBAC (each role restricted to its permitted screens and operations), and manual UAT (complete end-to-end user workflows for issue, return, seat reservation, and catalog search).

### 4.2.1 Test Case Summary

Table 9 summarizes all 16 test cases — all passed.

**Table 9: Test Case Summary (16/16 Passed)**

| TC # | Category | Description | Result |
|---|---|---|---|
| TC-01 | Authentication | Valid librarian login redirects to Admin dashboard | Pass |
| TC-02 | Authentication | Valid student login redirects to Student portal | Pass |
| TC-03 | Authentication | Invalid credentials are rejected with an error dialog | Pass |
| TC-04 | RBAC | Student cannot access the Book CRUD management panel | Pass |
| TC-05 | RBAC | Student cannot access the Member Registration panel | Pass |
| TC-06 | RBAC | Admin can force-clear any occupied seat; Student cannot | Pass |
| TC-07 | Book CRUD | New book record is saved and appears in catalog JTable | Pass |
| TC-08 | Book CRUD | Updated book metadata is reflected immediately in JTable | Pass |
| TC-09 | Book CRUD | Deleted book record is removed from catalog and blocks issuance | Pass |
| TC-10 | Issue/Return | Issuing a book sets BOOK.availability to FALSE | Pass |
| TC-11 | Issue/Return | Issuing an already-issued book displays rejection error | Pass |
| TC-12 | Issue/Return | Returning a book sets BOOK.availability back to TRUE | Pass |
| TC-13 | Seat Module | Clicking a FREE seat changes its state to RESERVED and repaints | Pass |
| TC-14 | Seat Module | Clicking an OCCUPIED seat displays rejection dialog | Pass |
| TC-15 | Seat Module | Admin Force-Clear sets seat state back to FREE and repaints | Pass |
| TC-16 | Persistence | All records (books, members, transactions) survive application restart | Pass |

## 4.3 Evaluation Against Objectives

Table 10 maps each project objective to its observed outcome.

**Table 10: Objective Evaluation**

| Objective | Outcome | Met? |
|---|---|---|
| OOP desktop application automating catalog and transaction cycle | Full CRUD and transaction processing implemented and validated (TC-07–TC-12) | Yes |
| Distinct user tiers through polymorphic role differentiation | Admin and Student roles correctly dispatched; privilege boundaries enforced (TC-04–TC-06) | Yes |
| Strict referential data integrity | All transactions reference verified book and member records; orphan prevention confirmed | Yes |
| Visual seat-finding matrix with real-time updates | Seat grid renders, reserves, and repaints correctly (TC-13–TC-15) | Yes |
| Cohesive dark-themed user interface | All screens conform to charcoal/amber/neon-emerald palette; no deviations observed | Yes |

## 4.4 Discussion

The observer-driven repaint mechanism performed as designed: every mutation to the in-memory two-dimensional seat-state array immediately triggered a paintComponent redraw, ensuring that the displayed grid was never out of synchronization with the underlying data model. The availability reconciliation algorithm correctly enforced mutual exclusion on book issuance, preventing the same copy from being issued to two members simultaneously.

The polymorphic role-dispatch approach cleanly separated administrative and student interfaces without duplicating shared UI components, validating the object-oriented class hierarchy as the appropriate architectural choice for this problem domain.

## 4.5 Limitations Identified During Testing

Three limitations were identified: (1) the seat-finding module models a single static floor plan and cannot be reconfigured without code changes; (2) there is no mechanism to track overdue books or calculate fines automatically; and (3) the test suite relies entirely on manual UAT with no automated regression coverage.

---

# Chapter 5

# Limitations and Future Work

## 5.1 Current Limitations

1. **Local execution only:** The application operates as a single-workstation deployment, preventing concurrent multi-terminal access by multiple librarians simultaneously.
2. **Static floor-plan model:** The seat matrix represents a fixed single-floor layout; adding rows, columns, or floors requires source code modification.
3. **No overdue management:** The system records return dates but does not automatically flag overdue books, calculate fines, or notify members.
4. **No mobile or remote access:** The Java Swing interface is confined to desktop contexts with no native mobile or web-based access pathway.
5. **No audit log for admin actions:** While transactions are logged, changes to the book catalog or member records (creates, updates, deletes) are not individually audited with timestamps and actor identity.
6. **No automated testing:** Validation relies entirely on manual UAT; no unit or integration test suite exists in the current artifact.
7. **Single-library scope:** The data model is tailored to a single library branch and would require schema changes to support multi-branch operations.

## 5.2 Future Work

1. **Barcode/RFID hardware integration:** Extend the issuance workflow with peripheral scanners for instantaneous book identification, eliminating manual ID entry at the desk.
2. **Automated overdue notification:** Incorporate scheduled background checks to flag overdue records and, in a networked configuration, dispatch email reminders to members.
3. **Multi-floor spatial pathfinding:** Expand the seat layout to support multi-floor representations augmented with shortest-path guidance to the nearest vacant seat.
4. **Web or mobile front-end:** Migrate the backend logic to a REST API and develop a responsive web client, allowing students to check seat availability and reserve seats remotely.
5. **Automated test suite:** Develop a JUnit-based unit and integration test suite covering the availability reconciliation algorithm, seat-state transitions, and JDBC persistence operations.
6. **Admin action audit log:** Record every catalog and member modification with a timestamp and the adminID of the acting user, providing a complete audit trail for institutional compliance.
7. **Fine management module:** Add automatic fine calculation based on configurable per-day rates and enable fine payment recording within the transaction processing workflow.

---

# Chapter 6

# Conclusion

This report has documented the design, implementation, and evaluation of a desktop-based Library Management System constructed upon Java SE and Java Swing. By replacing error-prone manual ledgers with a disciplined object-oriented architecture, the system demonstrably reduces administrative overhead, eliminates data redundancy, and enforces referential integrity across bibliographic, member, and spatial domains.

The system achieved all five stated objectives: automated catalog and transaction management through a fully CRUD-capable admin panel; clean role-based privilege separation through a polymorphic class hierarchy; strict referential integrity through a normalized relational schema; a visually intuitive, dynamically updating Computerized Seat-Finding Module; and a cohesive dark-themed interface consistent across all screens.

All 16 test cases passed, covering authentication, RBAC enforcement, book catalog operations, transaction processing, seat reservation and clearance, and data persistence. Known limitations — single-workstation deployment, a static floor-plan model, and the absence of automated testing — are well-scoped and form a clear roadmap for future development. Overall, the Library Management System demonstrates that disciplined object-oriented design and responsive Swing component rendering can replace error-prone manual procedures with a deterministic, auditable, and aesthetically refined digital solution.

---

## References

[1] Gosling, J., Joy, B., Steele, G., Bracha, G., & Buckley, A. (2021). *The Java Language Specification, Java SE Edition.* Oracle Corporation.

[2] Loy, M., Eckstein, R., Wood, D., Elliott, J., & Cole, B. (2012). *Java Swing* (2nd ed.). O'Reilly Media.

[3] Booch, G., Rumbaugh, J., & Jacobson, I. (2005). *The Unified Modeling Language User Guide* (2nd ed.). Addison-Wesley.

[4] Elmasri, R., & Navathe, S. B. (2016). *Fundamentals of Database Systems* (7th ed.). Pearson.

[5] Gamma, E., Helm, R., Johnson, R., & Vlissides, J. (1994). *Design Patterns: Elements of Reusable Object-Oriented Software.* Addison-Wesley.

[6] Sommerville, I. (2015). *Software Engineering* (10th ed.). Pearson.

[7] Oracle Corporation. (2023). *JDBC™ Database Access API Documentation.* Oracle Technology Network. Available online: https://docs.oracle.com/javase/8/docs/technotes/guides/jdbc/

[8] Bloch, J. (2018). *Effective Java* (3rd ed.). Addison-Wesley.
