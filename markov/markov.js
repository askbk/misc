export class MarkovChain {
    constructor(states = {}) {
        this.states = states;
    }

    addTransition(v, w) {
        if (!this.states.hasOwnProperty(v)) {
            this.states[v] = [w];

            if (!this.states.hasOwnProperty(w)) {
                this.states[w] = [];
            }
        } else {
            this.states[v].push(w);
        }
    }

    next(v) {
        const transitionCount = this.states[v].length;
        const n =  Math.floor(Math.random() * transitionCount);

        // console.log("next: " + this.states[v][n]);

        return this.states[v][n]
    }

    toString() {
        return this.states;
    }
}

export class TextGenerator {
    constructor(inputText = "", wordMode = false) {
        this.inputText = inputText;
        this.markovChain = new MarkovChain();
        this.wordMode = wordMode;
    }

    build(k = 1) {
        let prevState = "HEYAHSTART", currState;

        if (this.wordMode) {
            this.inputText = this.inputText.split(" ");

            for (let i = 0; i < this.inputText.length; i++) {
                currState = this.inputText[i];

                this.markovChain.addTransition(prevState, currState);

                prevState = currState;
            }

            this.markovChain.addTransition(currState, this.inputText[0]);

            console.log(this.markovChain);
            return;
        }
        for (let i = k; i < this.inputText.length; i++) {
            currState = this.inputText.substring(i - k, i);

            this.markovChain.addTransition(prevState, currState);

            prevState = currState;
        }
    }

    print(M = 30) {
        const startN = Math.floor(Math.random() * Object.keys(this.markovChain.states).length);

        // let prevState = Object.keys(this.markovChain)[startN];
        let prevState = "HEYAHSTART";
        let outputText = "";

        for (let i = 0; i < M; i++) {
            prevState = this.markovChain.next(prevState);

            if (this.wordMode) {
                outputText += prevState + " ";
            } else {
                outputText += prevState[prevState.length - 1];
            }
        }

        console.log(outputText);
    }
}
