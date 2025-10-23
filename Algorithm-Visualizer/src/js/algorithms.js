class SortingAlgorithms {
    async bubbleSort(array, updateDisplay) {
        const n = array.length;
        for (let i = 0; i < n - 1; i++) {
            for (let j = 0; j < n - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    // Swap elements
                    [array[j], array[j + 1]] = [array[j + 1], array[j]];
                    await updateDisplay(array, [j, j + 1]);
                }
            }
        }
        return array;
    }

    async selectionSort(array, updateDisplay) {
        const n = array.length;
        for (let i = 0; i < n - 1; i++) {
            let minIndex = i;
            for (let j = i + 1; j < n; j++) {
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                }
                await updateDisplay(array, [i, j]);
            }
            if (minIndex !== i) {
                [array[i], array[minIndex]] = [array[minIndex], array[i]];
                await updateDisplay(array, [i, minIndex]);
            }
        }
        return array;
    }

    async insertionSort(array, updateDisplay) {
        const n = array.length;
        for (let i = 1; i < n; i++) {
            let key = array[i];
            let j = i - 1;
            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                await updateDisplay(array, [j, j + 1]);
                j--;
            }
            array[j + 1] = key;
            await updateDisplay(array, [j + 1]);
        }
        return array;
    }

    async mergeSort(array, updateDisplay, start = 0, end = array.length - 1) {
        if (start >= end) {
            return;
        }
        
        const middle = Math.floor((start + end) / 2);
        await this.mergeSort(array, updateDisplay, start, middle);
        await this.mergeSort(array, updateDisplay, middle + 1, end);
        await this.merge(array, start, middle, end, updateDisplay);
        
        return array;
    }

    async merge(array, start, middle, end, updateDisplay) {
        const left = array.slice(start, middle + 1);
        const right = array.slice(middle + 1, end + 1);
        
        let i = 0, j = 0, k = start;
        
        while (i < left.length && j < right.length) {
            if (left[i] <= right[j]) {
                array[k] = left[i];
                i++;
            } else {
                array[k] = right[j];
                j++;
            }
            await updateDisplay(array, [k]);
            k++;
        }
        
        while (i < left.length) {
            array[k] = left[i];
            await updateDisplay(array, [k]);
            i++;
            k++;
        }
        
        while (j < right.length) {
            array[k] = right[j];
            await updateDisplay(array, [k]);
            j++;
            k++;
        }
    }

    async quickSort(array, updateDisplay, start = 0, end = array.length - 1) {
        if (start >= end) {
            return;
        }
        
        const pivotIndex = await this.partition(array, start, end, updateDisplay);
        await this.quickSort(array, updateDisplay, start, pivotIndex - 1);
        await this.quickSort(array, updateDisplay, pivotIndex + 1, end);
        
        return array;
    }

    async partition(array, start, end, updateDisplay) {
        const pivot = array[end];
        let i = start - 1;
        
        for (let j = start; j < end; j++) {
            if (array[j] < pivot) {
                i++;
                [array[i], array[j]] = [array[j], array[i]];
                await updateDisplay(array, [i, j]);
            }
        }
        
        [array[i + 1], array[end]] = [array[end], array[i + 1]];
        await updateDisplay(array, [i + 1, end]);
        
        return i + 1;
    }
}
