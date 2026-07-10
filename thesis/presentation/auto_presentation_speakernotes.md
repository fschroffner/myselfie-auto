# Speaker Notes — Teaching Type Inference

**Making `auto` tangible in Selfie**
Florian Schroffner · University of Salzburg

10-minute talk. One deep idea: *the type is already there — `auto` just keeps it.*
Everything else stays high level and feeds that one insight.

---

## Title slide

- Introduce yourself and the topic in one sentence.
- Frame the talk: this is about *teaching* a feature that is everywhere but invisible.
- "Today I want to show how we can make type inference — the `auto` keyword — something students can actually see, not just believe in."

---

## Slide 1 — Everyone uses it. Nobody sees how. (~1.5 min)

**Key message:** `auto` / `var` / `:=` is everywhere, but the mechanism is hidden.

- These keywords show up in C++, Rust, Go — almost every modern language.
- You write `auto` and the type "just appears." It feels like magic.
- Usually presented as deep type theory, full of formalism.
- Students use it daily without ever seeing it work.
- Land the hook: **"So how do you actually *teach* it?"** — then pause.

---

## Slide 2 — Shrink it until you can read it (~1.5 min)

**Key message:** Frame the project — `auto` in a compiler small enough to read.

- This is the whole project in one line: I added `auto` to Selfie.
- `auto p = malloc(8);` and the type comes out as a pointer.
- Why Selfie: it is a tiny teaching compiler you can read end to end — not production scale.
- `auto` infers the type of a local variable from its initialiser.
- Set up the deep dive with the closing question: **"But where does the type come from?"** — that question is the whole talk.

---

## Slide 3 — The whole grammar change (~1.5 min)

**Key message:** The language change is a single grammar production.

- A statement can now also be an `auto` declaration — that is the *entire* syntactic addition.
- New production: `auto_declaration = "auto" identifier "=" expression`.
- Stress that `expression` is *reused*: the exact rule the compiler already uses everywhere.
- Still LL(1): `auto` is a fresh keyword, no ambiguity.
- The production also draws the boundary: the `=` is mandatory (no `auto x;`), and a `void` initialiser is rejected — there is no value, so no type to bind. So `auto` only binds `uint64_t` or `uint64_t*`.

---

## Slide 4 — The type is already there (DEEP DIVE, ~3–4 min)

**Key message:** This is the heart of the project — inference is essentially one line.

- Walk it slowly. Take `auto p = malloc(8);`.
- The parser compiles the initialiser the way it compiles *any* expression. To emit code it must already know the type — here `malloc` yields `uint64_t*`.
- That type is sitting in the return value of `compile_expression()`. Normally it is used to type-check and then discarded.
- The one line `inferred_type = compile_expression();` simply *keeps* it. `auto` then records that type in the symbol table — done.
- Make the three points explicit: every expression already returns its type; `auto` just keeps it; no new analysis, no AST, no extra pass.
- Punchline: **"One line does the inference."** This is the moment the audience should *get* it.

---

## Slide 5 — And that is the whole feature (~1 min)

**Key message:** Small surface, fully tested. (The size numbers — anticipate this question.)

- Because the type was already there, the whole feature is tiny: ~55 lines of C* across three functions, only one new (`compile_auto_declaration`).
- No new pass, no AST, no change to the code generator.
- 14 small test programs (~136 lines), 24 automated autograder checks.
- The tests cover *both* directions: programs that must compile and run, and programs that must be rejected (e.g. the `void` initialiser).
- If asked "how big was it?" — this slide is the answer.

---

## Slide 6 — Small enough to understand (~1 min)

**Key message:** A complete, real feature you can read in full — the value.

- This is not a toy: it is a real, working feature that passes the autograder.
- Because it is small, you can read it top to bottom and understand every line.
- The point is pedagogical: the mechanism is made *visible*.
- Closing line, say it slowly:
  > "Type inference is not magic — it is the type the compiler already had."
- Tie back to the opening question: we made the invisible visible.

---

## Q&A prompts

- "How does this scale to real type systems?" → Selfie's goal is clarity, not completeness; the *idea* generalizes.
- "Why C and not a higher-level language?" → Selfie is self-contained and minimal by design.
- "How big was the change?" → see Slide 5: ~55 lines, one new function.
- Offer to show the actual source.
