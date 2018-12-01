(ns day-01
  (:require [clojure.string :as str]))

(try (def in (slurp "input/1.in"))
     (catch Exception e))

(def vs (map #(Integer/parseInt %) (str/split-lines in)))

;; part 1
(reduce + vs)

;; part 2
(loop [rem-vs (cycle vs)
       total 0
       seen-set #{}]
  (let [x (first rem-vs)]
    (if (contains? seen-set total)
      total
      (recur (rest rem-vs)
             (+ total x)
             (conj seen-set total)))))

