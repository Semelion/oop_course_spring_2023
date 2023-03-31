class MatrixS {
public:
    using SizeType = std::tuple<std::ptrdiff_t, std::ptrdiff_t>;
    
public:   
    explicit MatrixS(const SizeType& size = {0, 0});
    MatrixS(const std::ptrdiff_t m, const std::ptrdiff_t n);
    ~MatrixS();

    MatrixS(const MatrixS& other);
    MatrixS& operator=(const MatrixS& other);
    
    /**
     * \brief Возвращает элемент матрицы под индексами {i, j}
     * \param[in] elem индексы элемента
     * \return элемент матрицы
     * \throw std::out_of_range если i вне диапазона [0, m) или j вне диапазона [0, n)
     */
    [[nodiscard]] int& at(const SizeType& elem);
    [[nodiscard]] const int& at(const SizeType& elem) const;
    [[nodiscard]] int& at(const std::ptrdiff_t i, const std::ptrdiff_t j);
    [[nodiscard]] const int& at(const std::ptrdiff_t i, const std::ptrdiff_t j) const;
    
    /**
     * \brief Изменение размера матрицы
     * \param[in] new_size новый размер матрицы {new_m, new_n}
     * \throw std::invalid_argument если new_m <= 0 или new_n <= 0
     */
    void resize(const SizeType& new_size);
    void resize(const std::ptrdiff_t i, const std::ptrdiff_t j);

    /**
     * \return текущий размер матрицы {m, n}
     */
    [[nodiscard]] const SizeType& ssize() const noexcept;
    
    /**
     * \return количество строк в матрице (m)
     */
    [[nodiscard]] std::ptrdiff_t nRows() const noexcept;
    
    /**
     * \return количество столбцов в матрице (n)
     */
    [[nodiscard]] std::ptrdiff_t nCols() const noexcept;
};
