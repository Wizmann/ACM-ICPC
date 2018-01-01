function getGrade(score) {
    let grade;
    
    score = Math.max(0, score - 1);
    
    return "FEDCBA"[Math.floor(score / 5)];
}
