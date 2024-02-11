### Authors
    
- Mihails Daņilovs, md22039
- Rolands Pučeta, rp22046
- Kristofers Semjonovs, ks22110
- Aleksis Volrāts, av22110
- Ralfs Čipāns, rc22007

### Function Description for "Create Course" (Identifikators: KURS_001)

#### Overview

The "Create Course" functionality, designated by the identifier KURS_001, is designed to create course templates within the "Mācies un Dalies" platform. This feature is primarily aimed at user groups such as Administrators and Content Creators, allowing them to define, organize, and offer educational content to clients.

#### Input Data Requirements
  
- **Course Name (Kursa nosaukums):** A string of up to 100 characters, accommodating upper and lower case Latin alphabet letters, with or without diacritics (garumzīmes un mīkstinājumi), numbers, and symbols. The name should accurately reflect the course content and appeal to potential clients.

- **Course Category (Kursa kategorija):** A descriptive string, also up to 100 characters, which may include multiple words separated by spaces, numbers, and symbols. Categories should be derived from the unique attributes of the course's lessons to facilitate organized browsing by users.

- **Preview Image (Priekšskatījuma attēls):** An image in JPEG, JPG, or PNG format, not exceeding 3 MB in size, intended to visually represent the course to potential clients.

- **Course Description (Kursa apraksts):** A detailed description of the course, up to 1000 characters, using the Latin alphabet with diacritics, numbers, and symbols. This should provide potential clients with a clear understanding of the course's objectives, content, and structure.

- **Course Price (Kursa cena):** A decimal number with up to two digits following the decimal point, and a maximum of four digits before it, reflecting the cost of enrollment in the course.

#### Processing

Upon the activation of the "Create Course" confirmation button, the system initiates a series of validations to ensure all entered data meets the predefined criteria. Validated data is then transmitted to the system's database for storage and further processing. This step is crucial for making the course available to users and for integrating it within the platform's course offerings.

#### Output Data

Successful course creation is confirmed to the user through a notification message stating "Kurss izveidots!" (Course Created!). This acknowledgment serves as a cue to the user that their course is now part of the platform's educational content.

#### Error Handling

The system is equipped to handle various errors that may arise during the course creation process, providing specific feedback to guide users in fixing the issue. Error messages include:

- **ERROR_001:** "Lūdzu aizpildiet visus obligātos laukus!" (Please fill in all mandatory fields!)
- **ERROR_002:** "Kļūda ievadē! Pārliecinieties, vai ievadītie dati ir pareizi!" (Input error! Please ensure the entered data is correct!)
- **ERROR_004:** "Attēls ir lielāks par maksimālo atļauto izmēru!" (The image exceeds the maximum allowed size!)
- **ERROR_009:** "Ievadītais teksts pārsniedz atļauto simbolu skaitu!" (The entered text exceeds the allowed number of symbols!)
- **ERROR_011:** "Attēlam jābūt formātā JPEG, JPG vai PNG!" (The image must be in JPEG, JPG, or PNG format!)
- **ERROR_012:** "Kļūda! Lūdzu atkārtojiet darbību!" (Error! Please repeat the action!)