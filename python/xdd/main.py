from csv import reader

with open("IGFollow__.ko.mal.__300_following_prev.csv", "r", encoding="utf-8") as prev:
    with open("IGFollow__.ko.mal.__299_following_next.csv", "r", encoding="utf-8") as next:
        prev = {row[1] for row in reader(prev)}
        next = {row[1] for row in reader(next)}
        print(prev - next)
        print(next - prev)