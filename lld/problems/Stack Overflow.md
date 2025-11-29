<img width="1465" height="697" alt="image" src="https://github.com/user-attachments/assets/1676b546-7e49-4694-89a4-cc13c97364a7" />

# StackOverflow PlantUML Explanation (Plain English)

Ah! Now I get it — you want the PlantUML explained like a story of interactions: who calls whom, who owns what, who uses what, etc., in plain English, step by step. Let’s do that for StackOverflow:

---

## 1. Users

- `User` represents a person on the platform.
- Users call `StackOverflowService` to perform actions:
  - Post a question (`postQuestion`)
  - Post an answer (`postAnswer`)
  - Vote on posts (`voteOnPost`)
  - Accept an answer (`acceptAnswer`)
  - Search questions (`searchQuestions`)
- **Relationship:** `User → StackOverflowService` (association / uses)

---

## 2. StackOverflowService

- Acts as a **facade** (main interface) hiding complexity.
- Internally, it **owns** collections of:
  - Users
  - Questions
  - Answers
- Responsibilities:
  1. Creates and stores users.
  2. Creates questions and answers, attaches observers (like `ReputationManager`).
  3. Finds posts to vote on.
  4. Runs searches using `SearchStrategy`.
- **Relationship:** `StackOverflowService *-- User` (composition: owns users), same for Questions & Answers

---

## 3. Questions and Answers

- `Question` **is-a** `Post` → inherits voting, comments, and observer behavior.
- `Answer` **is-a** `Post`.
- **Relationships:**
  - `Question *-- Answer` → A question owns multiple answers
  - `Post *-- Comment` → A post owns multiple comments
  - `Question o-- Tag` → A question has tags (tags exist independently)
- Voting: When a user votes, the `Post.vote()` method is called, which notifies observers (`ReputationManager`)

---

## 4. Observer Pattern

- `Post` keeps a list of `PostObservers` (`Post *-- PostObserver`)
- `ReputationManager` implements `PostObserver` (`PostObserver <|.. ReputationManager`)
- Flow:
  1. User votes on a post → calls `Post.vote()`
  2. `Post` notifies all observers (`notifyObservers`)
  3. `ReputationManager` updates the user’s reputation based on the event

---

## 5. Comments

- `Comment` **is-a** `Content`
- Comments belong to a Post (`Post *-- Comment`)
- Comments **cannot be voted on**, so they don’t trigger reputation changes

---

## 6. Tags

- Tags are just labels: `Question o-- Tag`
- They help with searching and filtering but exist independently from questions

---

## 7. Search Strategies

- `SearchStrategy` is an interface
- `KeywordSearchStrategy`, `TagSearchStrategy`, `UserSearchStrategy` implement it
- `StackOverflowService` **uses** these strategies (`StackOverflowService --> SearchStrategy`) to filter questions

---

## 8. Events

- When an action happens (vote/accept), an `Event` object is created:
  - Links the **actor** (`User`) and the **targetPost**
  - Sent to observers to trigger side effects (like updating reputation)
- **Relationship:** `Event o-- User` and `Event o-- Post`

---

## 9. Story Flow (End-to-End)

1. **Alice (User)** calls `StackOverflowService.postQuestion()`
2. `StackOverflowService` creates a `Question` object
3. `Question` owns its answers list; initially empty
4. **Bob (User)** calls `StackOverflowService.postAnswer()`
5. `StackOverflowService` creates an `Answer` and adds it to the `Question`’s answers
6. **Charlie (User)** votes on the answer → `Post.vote()` is called
7. `Post` notifies `ReputationManager` → updates the author’s reputation
8. **Alice** accepts an answer → triggers `ACCEPT_ANSWER` event → updates reputation
9. Users can also search: `StackOverflowService.searchQuestions()` uses strategies to filter results by tag, keyword, or author

---

## ✅ Summary of “who calls who / owns what / uses what”

| From | Action / Relationship | To |
|------|---------------------|---|
| User | calls | StackOverflowService |
| StackOverflowService | owns | Users, Questions, Answers |
| Question | owns | Answers |
| Post | owns | Comments |
| Question | has | Tags |
| Post | notifies | PostObserver (ReputationManager) |
| StackOverflowService | uses | SearchStrategy |
| Event | links | User (actor), Post (target) |

