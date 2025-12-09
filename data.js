// ------- DEFAULT STUDENT DATA (used only first time) -------
let defaultStudents = [
  { username: "s101", password: "pass101", roll: 101, name: "Arjun", dept: "CSE", perf: 85 },
  { username: "s102", password: "pass102", roll: 102, name: "Meera", dept: "ECE", perf: 78 },
  { username: "s103", password: "pass103", roll: 103, name: "Ravi",  dept: "IT",  perf: 92 }
];

// ------- ADMIN ACCOUNTS -------
let admins = [
  { username: "admin1", password: "admin123" },
  { username: "principal", password: "principal123" }
];

// ------- TEACHER ACCOUNTS -------
let teachers = [
  { username: "teacher1", password: "teach123" },
  { username: "teacher2", password: "abc123" }
];

// ------- STUDENT ACCOUNTS (LOAD FROM STORAGE IF EXISTS) -------
let students;

// try to load saved students from localStorage
let saved = localStorage.getItem("students");
if (saved) {
  try {
    students = JSON.parse(saved);
  } catch (e) {
    students = defaultStudents;
  }
} else {
  // first time -> use defaults
  students = defaultStudents;
}
