קודם כל אסביר על מימוש הפונקציות השונות במטלה:
הפונקציות ב- Graph.cpp: 
הראשונה: loadGraph מקבלת מטריצה וטוענת אותה לתוך הגרף.
בודקת אם הגרף מכוון, אם יש צלעות שליליות, משקל וכו׳ ונותנת ערכים לשדות המתאימים בהתאם לזה.
הפונקציה הבאה printGraph - אם הגרף לא מכוון נספור כל שתי צלעות כאחת, כי אין כיוונים לכן הצלע מקודקוד 0 ל-1
ומקודקוד 1 ל-0 זה אותה צלע. לכן נדפיס את סה״כ הצלעות שספרנו ונחלק ב-2.
אם הגרף מכוון נדפיס פשוט את סה״כ הצלעות שספרנו.
הפונקציות ב- Algorithms.cpp: 
הראשונה isConnected(g) - מקבלת גרף ובודקת האם הוא קשיר.
נעשה זאת ע״י DFSAlgo פונקציה שכתבנו במחלקת DFS שעושה DFS מקודקדוד.
אם הגרף לא מכוון נריץ DFS פעם אחת ואם יש קודקוד שלא ביקרנו בו אז הגרף לא קשיר.
אם ביקרנו בכל הקודקודים בגרף הגרף קשיר.
אם הגרף מכוון נריץ DFS מכל קודקוד ונבדוק שביקרנו בכל הקודקודים, כי לצלעות כעת יש כיווו אז יכול להיות
שמקודקוד אחד אפשר להגיע לאחר אך מאחר אי אפשר להגיע אליו. אם יש קודקוד שלא ביקרנו בו אז הגרף לא קשיר.
אם ביקרנו בכל הקודקודים בכל הריצות הגרף קשיר.
