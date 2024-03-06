const board = [
    ['s', 'o', 's', 'o'],
    ['s', 'o', 'o', 's'],
    ['s', 's', 's', 's']
]
function filterBoard(board, word) {
    let matches = 0
    for (let i = 0; i < board.length; i++) {
        for (let j = 0; j < board[i].length; j++) {
            const insideMatches = {
                h: [],
                v: [],
                d: []
            }
            for (let letterWord = 0; letterWord < word.length; letterWord++) {
                if (board[i] && board[i][j + letterWord]) {
                    insideMatches.h.push(board[i][j + letterWord])
                }
                if (board[i + letterWord] && board[i + letterWord][j]) {
                    insideMatches.v.push(board[i + letterWord][j])
                }
                if (board[i + letterWord] && board[i + letterWord][j + letterWord]) {
                    insideMatches.d.push(board[i + letterWord][j + letterWord])
                }
            }
            Object.keys(insideMatches).forEach(key => {
                const matchedWord = insideMatches[key].join('')
                if (matchedWord === word) {
                    matches++
                }
            })
        }
    }
    console.log(matches)
}
filterBoard(board, 'sos')