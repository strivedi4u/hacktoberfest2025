class AlgorithmVisualizer {
    constructor() {
        this.array = [];
        this.arraySize = 50;
        this.algorithms = new SortingAlgorithms();
        this.sorting = false;
        this.speed = 50;

        this.setupEventListeners();
        this.generateArray();
    }

    setupEventListeners() {
        document.getElementById('generate').addEventListener('click', () => this.generateArray());
        document.getElementById('sort').addEventListener('click', () => this.startSorting());
        document.getElementById('speed').addEventListener('input', (e) => {
            this.speed = parseInt(e.target.value);
        });
    }

    generateArray() {
        this.array = Array.from({length: this.arraySize}, () => 
            Math.floor(Math.random() * 300) + 10
        );
        this.displayArray();
    }

    displayArray(comparingIndices = []) {
        const container = document.getElementById('array-container');
        container.innerHTML = '';
        const maxVal = Math.max(...this.array);
        
        this.array.forEach((value, index) => {
            const bar = document.createElement('div');
            bar.className = 'array-bar';
            bar.style.height = `${(value / maxVal) * 100}%`;
            bar.style.width = `${100 / this.arraySize}%`;
            
            if (comparingIndices.includes(index)) {
                bar.classList.add('comparing');
            }
            
            container.appendChild(bar);
        });
    }

    async startSorting() {
        if (this.sorting) return;
        this.sorting = true;
        
        const algorithm = document.getElementById('algorithm').value;
        const sortButton = document.getElementById('sort');
        const generateButton = document.getElementById('generate');
        
        sortButton.disabled = true;
        generateButton.disabled = true;
        
        const updateDisplay = async (array, comparingIndices) => {
            this.array = [...array];
            this.displayArray(comparingIndices);
            await new Promise(resolve => setTimeout(resolve, 101 - this.speed));
        };
        
        try {
            switch(algorithm) {
                case 'bubble':
                    await this.algorithms.bubbleSort(this.array, updateDisplay);
                    break;
                case 'selection':
                    await this.algorithms.selectionSort(this.array, updateDisplay);
                    break;
                case 'insertion':
                    await this.algorithms.insertionSort(this.array, updateDisplay);
                    break;
                case 'merge':
                    await this.algorithms.mergeSort(this.array, updateDisplay);
                    break;
                case 'quick':
                    await this.algorithms.quickSort(this.array, updateDisplay);
                    break;
            }
            
            // Show completion state
            this.displayArray();
            
        } catch (error) {
            console.error('Sorting error:', error);
        }
        
        sortButton.disabled = false;
        generateButton.disabled = false;
        this.sorting = false;
    }
}

// Initialize the visualizer when the page loads
window.addEventListener('load', () => {
    new AlgorithmVisualizer();
});
